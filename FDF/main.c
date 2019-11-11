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
    int                 **array;
    int                 step;
    int                 bpp;
    int                 endian;
    int                 size_line;
    int                 x_start;
    int                 y_start;
    int                 **colors;
    double              x_rotate;
    double              y_rotate;
    double              z_rotate;
}                       t_fdf;

void  erase_img(t_fdf *fdf)
{
    int i;

    i = 0;
    while(i != 1000000-1)
    {
        (fdf->img_data)[i] = 0x000000;

        i++;
    }
    mlx_put_image_to_window(fdf->mlx_ptr,fdf->win_ptr,fdf->img_ptr, 0, 0);
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



static void x_rotate(int *y, int *z, t_fdf *fdf)//num0
{
    int previous_y;
    int previous_z;

    previous_z = *z;
    previous_y = *y;
    *y = previous_y * cos(fdf->x_rotate) + previous_z * sin(fdf->x_rotate);
    *z = -previous_y * sin(fdf->x_rotate) + previous_z * cos(fdf->x_rotate);

   fdf->x_rotate += (0.001);
}

static void y_rotate(int *x,int *z, t_fdf *fdf)
{
    int     previous_x;
    int     previous_z;

    previous_x = *x;
    previous_z = *z;
    *x = previous_x * cos(fdf->y_rotate) + previous_z * sin(fdf->y_rotate);
    *z = -previous_x * sin(fdf->y_rotate) + previous_z * cos(fdf->y_rotate);
    fdf->y_rotate+=(0.001);
}

static void z_rotate(int *x, int *y, t_fdf *fdf)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = previous_x * cos(fdf->z_rotate) - previous_y * sin(fdf->z_rotate);
    *y = previous_y * sin(fdf->z_rotate) + previous_y * cos(fdf->z_rotate);
    fdf->z_rotate+=(0.001);
}

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void    make_horizontal_line(t_fdf *fdf, int x_start, int y_start, int z, int next_z)
{
    int y_end;
    int x_end;
    int rotate_x;
    int rotate_y;
    int rotate_z;
    int rotate_z_next;

    y_end = y_start;
    x_end =x_start + fdf->step;
    rotate_x = x_start;
    rotate_y = y_start;
    rotate_z = z;
    rotate_z_next = next_z;

    if (fdf->dimension == 'x')
    {
        x_rotate(&y_end, &rotate_z_next, fdf);
        x_rotate(&rotate_y, &rotate_z,fdf);
    }
    else if (fdf->dimension == 'y')
    {
        y_rotate(&x_end, &rotate_z_next, fdf);
        y_rotate(&rotate_x, &rotate_z, fdf);
    }
    else if (fdf->dimension == 'z')
    {
        z_rotate(&x_end, &y_end, fdf);
        z_rotate(&rotate_x, &rotate_y, fdf);
    }
 iso(&x_end, &y_end, rotate_z_next);
  iso(&rotate_x, &rotate_y, rotate_z);

    make_line(rotate_x, rotate_y, x_end,y_end, fdf->img_data,0x9b30ff);
}

void    make_vertical_line(t_fdf *fdf, int x_start, int y_start, int z, int next_z)
{
    int y_end;
    int x_end;
    int rotate_x;
    int rotate_y;
    int rotate_z;
    int rotate_z_next;

    y_end = y_start + fdf->step;
    x_end =x_start;
    rotate_x = x_start;
   rotate_y = y_start;
    rotate_z = z;
    rotate_z_next = next_z;

    if (fdf->dimension == 'x')
    {
        x_rotate(&y_end, &rotate_z_next, fdf);
        x_rotate(&rotate_y, &rotate_z,fdf);
    }
    else if (fdf->dimension == 'y')
    {
        y_rotate(&x_end, &rotate_z_next, fdf);
        y_rotate(&rotate_x, &rotate_z, fdf);
    }
    else if (fdf->dimension == 'z')
    {
        z_rotate(&x_end, &y_end, fdf);
        z_rotate(&rotate_x, &rotate_y, fdf);
    }
   iso(&x_end, &y_end, rotate_z_next);
  iso(&rotate_x, &rotate_y, rotate_z);
    make_line(rotate_x, rotate_y, x_end, y_end, fdf->img_data,0xff7f);
}

void    print_2d_arr(int  **arr, int cols, int rows)
{
    int i;
    int j;

    i = 0;
    while (i <rows)
    {
        j = 0;
        while (j < cols)
        {
            printf("%i ", arr[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

int     **create_2d_int_arr(int cols, int rows)
{
    int **result;
    int i;
    int j;
    i = 0;
    if (!(result = (int **)ft_memalloc(sizeof(int *) * (size_t)rows + 1)))
        return (NULL);
    while (i < cols)
    {
        j = 0;
        if (!(result[i] = (int *)ft_memalloc(sizeof(int) * (size_t)cols + 1)))
            return (NULL);
        while (j < rows)
        {
            result[i][j] = 0;
            j++;
        }
        i++;
    }
    result[i] = NULL;
    return (result);
}

void       draw_all(t_fdf *fdf, int cols, int rows)
{
    int x_start = fdf->x_start;
    int y_start = fdf->y_start;
    int x;
    int y;

    y = 0;
    while (y < cols)//y <= cols
    {
        x = 0;
        while (x < rows)//x <= rows
        {
            if (x + 1 < rows)
              make_horizontal_line(fdf,x_start, y_start, fdf->array[y][x],fdf->array[y][x + 1]);
           if (y + 1 < cols)
               make_vertical_line(fdf,x_start,y_start,fdf->array[y][x],fdf->array[y + 1][x]);
            x_start+=fdf->step;
            x++;
        }
        x_start = fdf->x_start;
        y_start+=fdf->step;
        y++;
    }
    mlx_put_image_to_window(fdf->mlx_ptr,fdf->win_ptr,fdf->img_ptr,0,0);
}

void    create_fdf_data(t_fdf *fdf, int step, int width, int height)
{
    void    *win_ptr;
    int     *img_data;
    void    *img_ptr;

    fdf->step =step;
    win_ptr = mlx_new_window(fdf->mlx_ptr, width, height, "little_cat");//создаем новое окно
    fdf->win_ptr = win_ptr;
    img_ptr = mlx_new_image(fdf->mlx_ptr,width, height);
    fdf->img_ptr = img_ptr;
    img_data = (int *)mlx_get_data_addr(img_ptr, &(fdf->bpp), &(fdf->size_line), &(fdf->endian));
    fdf->img_data = img_data;
    fdf->x_start = 500;
    fdf->y_start = 200;
}

int key_press(int keycode, t_fdf *fdf)//закрывает окошко пр  нажатии клавиши еск.Возможно нужно переделать
{
    fdf->colors=0;
    if(keycode == 53)//esc
    {
        exit(0);
    }
    if(keycode == 124)//стрелка вправо
    {
     //   printf(" right! ");
        erase_img(fdf);
        fdf->x_start+=10;
        draw_all(fdf, 4,4);
    }
    if(keycode == 126)//стрелка вниз
    {
     //   printf(" down! ");
        erase_img(fdf);
        fdf->y_start+=10;
        draw_all(fdf, 4,4);
    }
    if(keycode == 123)//стрелка влево
    {
      //  printf(" left! ");
        erase_img(fdf);
        fdf->x_start-=10;
        draw_all(fdf, 4,4);
    }
    if(keycode == 125)//стрелка вверх
    {
      //  printf(" up! ");
        erase_img(fdf);
        fdf->y_start-=10;
        draw_all(fdf, 4,4);
    }
    if (keycode == 88)//num6  для поворота по Х
    {
     //   printf(" x_d! ");
        erase_img(fdf);
        fdf->dimension = 'x';
        draw_all(fdf, 4,4);
       fdf->dimension = 'i';
    }
    if (keycode == 91)//num2  для поворота по У
    {
     //   printf(" y_d! ");
        erase_img(fdf);
        fdf->dimension = 'y';
        draw_all(fdf, 4,4);
        fdf->dimension = 'i';
    }
    if (keycode == 87)//num5  для поворота по Z
    {
       // printf(" z_d! ");
        erase_img(fdf);
        fdf->dimension = 'z';
        draw_all(fdf, 4,4);
        fdf->dimension = 'i';
    }
    return (0);
}

int		main()
{
    void    *mlx_ptr;
    t_fdf   *fdf;

   // if (ac == 2)
   // {
        fdf = ft_memalloc(sizeof(t_fdf));
        mlx_ptr = mlx_init();//инициализируем
        fdf->mlx_ptr = mlx_ptr;
        int    **test_arr2 = create_2d_int_arr(4, 4);

    //test_arr2[2][2] = 80;
    //test_arr2[2][3] = 80;
    //test_arr2[1][1] = 80;
    test_arr2[1][2] = 80;
    test_arr2[2][1] = 80;



        print_2d_arr(test_arr2, 4,4);
        fdf->array = test_arr2;
        create_fdf_data(fdf,10,1000,1000);
        draw_all(fdf, 4,4);
        mlx_hook(fdf->win_ptr,2, 0, key_press, fdf);//отлавливаем нажатие клавиш
        mlx_loop(fdf->mlx_ptr);
  //  }
    //почистить фдф и массив
    return (0);
}
