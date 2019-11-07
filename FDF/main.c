/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:13:28 by jslave            #+#    #+#             */
/*   Updated: 2019/11/05 18:13:32 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib/mlx.h"

#include "libft/includes/libft.h"
#include <fcntl.h>

#define BUF_SIZE 500



#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct          s_fdf
{
    void                *win_ptr;
    void                *mlx_ptr;
    void                *img_ptr;
    int                 *img_data;
    char                dimension;
    int                 step;
    int                 bpp;
    int                 endian;
    int                 size_line;
}                       t_fdf;

int key_press(int keycode, void *param)//закрывает окошко пр  нажатии клавиши еск.Возможно нужно переделать
{
    if(!param && keycode == 53)
        exit(0);
    return (0);
}

static void iso(int *x, int *y, int z)
{


    if (z == 30)
        printf("HEIGHT\n");
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
  //  printf("previous_x: %d  ", previous_x);
 //   printf("previous_y: %d\n", previous_y);
    *x = abs(previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
   // printf("new x is: %d  ", *x);
   // printf("new y is: %d\n", *y);
}


void make_line(int x_start, int y_start, int x_end, int y_end, int *img_data, int color)
{
    int x,y,dx,dy,dx1,dy1,px,py,xe,ye;
    dx = x_end -x_start;
    dy = y_end -y_start;

    dx1 = abs(dx);
    dy1 = abs(dy);
    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;
    if (dy1 <= dx1)
    {
        if (dx >=0)
        {
            x = x_start;
            y = y_start;
            xe = x_end;
        }
        else
        {
            x = x_end;
            y = y_end;
            xe = x_start;
        }
        //img_data[y * 1000 + x] = color;
        img_data[y * 1000 + x] = 0xcdcd00;
        while (x < xe) {
            x+=1;
            if (px < 0)
                px = px + 2 * dy1;
            else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    y += 1;
                else
                    y -= 1;
                px = px + 2 * (dy1 - dx1);

            }
            img_data[y * 1000 + x] = color;
        }
    }
    else {
        if (dy >= 0) {
            x = x_start;
            y = y_start;
            ye = y_end;
        } else {
            x = x_end;
            y = y_end;
            ye = y_start;
        }
        //img_data[y * 1000 + x] = color;
        img_data[y * 1000 + x] = 0xcdcd00;
        while (y < ye) {
            y += 1;
            if (py <= 0)
                py = py + 2 * dx1;
            else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    x += 1;
                else
                    x -= 1;
                py = py + 2 * (dx1 - dy1);
            }
            img_data[y * 1000 + x] = color;
        }
    }
}

void    make_horizontal_line(t_fdf *fdf, int x_start, int y_start, int z, int next_z)
{
    int y_end;
    int x_end;
    int iso_x;
    int iso_y;

    y_end = y_start;
    x_end =x_start + fdf->step;
    iso_x = x_start;
    iso_y = y_start;

    iso(&x_end, &y_end, next_z);
    iso(&iso_x, &iso_y, z);
    make_line(iso_x,iso_y,x_end,y_end,fdf->img_data,0x9b30ff);
}

void    make_vertical_line(t_fdf *fdf, int x_start, int y_start, int z, int next_z)
{
    int y_end;
    int x_end;
    int iso_x;
    int iso_y;

    y_end = y_start  + fdf->step;
    x_end =x_start;
    iso_x = x_start;
    iso_y = y_start;

    iso(&x_end, &y_end, next_z);
    iso(&iso_x, &iso_y, z);
    make_line(iso_x,iso_y,x_end,y_end,fdf->img_data,0xff7f);
}

void    print_arr(int **sqrt, int size)//delete
{
    int		i;
    int		j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            printf("%i  ", sqrt[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int	    **make_2d_arr(int size)//delete or move to the lib
{
    int	**sqrt;
    int		i;
    int		j;

    i = 0;
    if (!(sqrt = (int **)ft_memalloc(sizeof(int *) * (size_t)size + 1)))
        return (NULL);
    while (i < size)
    {
        j = 0;
        if (!(sqrt[i] = (int *)ft_memalloc(sizeof(int) * (size_t)size + 1)))
            return (NULL);
        while (j < size)
        {
            sqrt[i][j] = 0;
            j++;
        }
        i++;
    }
    sqrt[i] = NULL;
    return (sqrt);
}

void    draw_all(t_fdf *fdf, int **ex, int size)
{
    int x_start = 600;
    int y_start = 100;
    int		i;
    int		j;
    int x_temp;
    x_temp = x_start;

    i = 0;

    while (i < size)
    {
        j = 0;
        while (j < size && (i + 1 < size) && (j + 1) < size)
        {
            make_horizontal_line(fdf,x_start,y_start,ex[i][j], ex[i][j+ 1]);//violet
            make_vertical_line(fdf, x_start, y_start, ex[i][j], ex[i + 1][j]);//green
            j++;
            x_start+=fdf->step;
            make_vertical_line(fdf, x_start, y_start, ex[i][j], ex[i + 1][j]);//green
        }
       x_start = x_temp;
       y_start+=fdf->step;
       i++;
    }
    j = 0;
    i--;
    y_start-=fdf->step;
    while (j+1 < size)
    {
        make_horizontal_line(fdf,x_start,y_start,ex[i][j], ex[i][j+1]);//violet
        j++;
        x_start+=fdf->step;
    }

}

int		main(int ac, char **av)
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     *img_data;
    void    *img_ptr;
    t_fdf   *fdf_main;
    int fd;

    int **test_arr = make_2d_arr(8);

    test_arr[3][3] = 80;
    test_arr[3][4] = 80;
    test_arr[4][3] = 80;
    test_arr[4][4] = 80;

    print_arr(test_arr,8);
    if (ac == 2)
    {
        fdf_main = ft_memalloc(sizeof(t_fdf));
        fdf_main->step = 30;
        mlx_ptr = mlx_init();//инициализируем
        fdf_main->mlx_ptr = mlx_ptr;
        char *line;
        fd = open(av[1], O_RDONLY);
        while (get_next_line(fd, &line) == 1)
            printf("line is: %s\n", line);
        win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "little_cat");//создаем новое окно
        fdf_main->win_ptr = win_ptr;
        mlx_hook(win_ptr,2, 0, key_press, ((void *)0));//отлавливаем нажатие клавиш esc
        img_ptr = mlx_new_image(mlx_ptr,1000,1000);
        fdf_main->img_ptr = img_ptr;
        img_data = (int *)mlx_get_data_addr(img_ptr, &(fdf_main->bpp), &(fdf_main->size_line), &(fdf_main->endian));
        fdf_main->img_data = img_data;
        draw_all(fdf_main, test_arr, 8);
        mlx_put_image_to_window(mlx_ptr,win_ptr,img_ptr,0,0);
        mlx_loop(mlx_ptr);
    }
    return (0);
}