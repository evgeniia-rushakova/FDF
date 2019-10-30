/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:55:55 by jslave            #+#    #+#             */
/*   Updated: 2019/10/25 16:55:59 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib/mlx.h"

#include "libft/includes/libft.h"
#include <fcntl.h>

#define BUF_SIZE 500



#include <stdio.h>
#include <unistd.h>

typedef struct      s_point
{
    void                *win_ptr;
    void                *img_ptr;
    void                *mlx_ptr;
    int                 color;
    int                 x_coord;
    int                 y_coord;
    int                 z_coord;
    struct  s_point     *next;
}                   t_point;



int key_press(int keycode, void *param)//закрывает окошко пр  нажатии клавиши еск.Возможно нужно переделать
{
	if(!param && keycode == 53)
		exit(0);
	return (0);
}

int     swap_dots(int start, int end, int param)//позволяет поменять местами старт и енд если они начальная координата меньше конечной
{
    int buf;

    if (start > end)
    {
        buf = start;
        start = end;
        end = buf;
    }
    return (param == 1 ? start : end);
}

void	make_line(int x_start, int y_start, int x_end, int y_end, void *mlx_ptr, void *win_ptr, int color)//Чертит линию из точки А в точку Б.Параметры винптр млх_птр и цвет потом будут лежать в структуре
{
	int delta_x;
	int delta_y;
	int coeff;
	int i;

	i = x_start;
	x_start = swap_dots(x_start, x_end, 1);
    x_end = swap_dots(i,x_end,2);
    i = y_start;
    y_start = swap_dots(y_start, y_end, 1);
    y_end = swap_dots(i, y_end, 2);
	delta_x = x_end - x_start;
	delta_y = y_end - y_start;

	if (delta_x != 0)
	    i = delta_x;
	else
	    i = delta_y;
	coeff = 2 * delta_y - delta_x;
	mlx_pixel_put(mlx_ptr,win_ptr,x_start,y_start, 0xcfff24);//Начальная точка.Надо потом убрать или нет?
	while (i-- >= 0)
	{
		if (coeff >= 0)
		{
		    if (delta_x != 0)
		        x_start+=1;
			if(delta_y != 0)
			    y_start+=1;
			coeff = coeff + 2 *(delta_y - delta_x);
		}
		else
		{
		    if (delta_x != 0)
		        x_start+=1;
			coeff = coeff * 2 * delta_y;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, x_start, y_start, color);
	}
}

void    make_web(int col, int row, int width, void *mlx_ptr, void *win_ptr)//бесполезная функция
{
    int start_x = 50;
    int start_y = 50;
    int i = 0;

    while (row != -1)
    {
        while (i != col)
        {
            make_line(start_x,start_y,start_x + width,start_y,mlx_ptr,win_ptr,0x4169e1);
            make_line(start_x,start_y,start_x,start_y + width, mlx_ptr, win_ptr, 0x7b68ee);
            start_x+=width;
            make_line(start_x,start_y,start_x,start_y + 50, mlx_ptr, win_ptr, 0x7b68ee);
             i++;
        }
        start_x = 50;
        start_y+=width;
        i = 0;
        row--;
    }
}

int    rotate_x(int keycode, t_point *param)
{
    if (keycode == 124)
    {
        make_line(param->x_coord,param->y_coord,param->next->x_coord, param->next->y_coord,param->mlx_ptr,param->win_ptr, 0xffff00);
        printf("old: %d  ", param->x_coord);
        param = param->next;
        printf("new: %d  \n", param->x_coord);
    }
    return (0);
}

t_point *make_list_of_points(t_point *start, void *win_ptr, void *mlx_ptr, int quan_of_points)//по такому принципу создать кусочек списка для каждой точки
{
    t_point *copy;
    copy = start;
    int start_x = 50;
    int start_y = 50;
    while (quan_of_points > 0)
    {
        copy->win_ptr = win_ptr;
        copy->mlx_ptr = mlx_ptr;
        copy->x_coord = start_x;
        copy->y_coord = start_y;
        start_x+=50;
        start_y+=50;
        if(quan_of_points - 1 != 0)
            copy->next = ft_memalloc(sizeof(t_point));
        copy = copy->next;
        quan_of_points--;
    }
    return (start);
}

int		main(int ac, char **av)
{
	char *line;
	int fd;
	line = NULL;
	//int res;

	void	*mlx_ptr;
	void	*win_ptr;
	//void	*img_ptr;
	//char	*data_ptr;

	t_point *start = ft_memalloc(sizeof(t_point));
	mlx_ptr = mlx_init();//инициализируем

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		/*while (get_next_line(fd, &line) == 1)
			printf("line is: %s\n", line);*/

		win_ptr = mlx_new_window(mlx_ptr, 800, 800, "little_cat");//создаем новое окно
        mlx_hook(win_ptr,2, 0, key_press, ((void *)0));//отлавливаем нажатие клавиш esc

       make_line(400, 400,400, 200, mlx_ptr, win_ptr, 0x8b0a50 );
       make_line(400, 400, 328, 328,mlx_ptr,win_ptr, 0xff3e96);

       make_list_of_points(start, win_ptr, mlx_ptr,6);
       mlx_hook(win_ptr,3,0, rotate_x, start);//отлавливаем нажатие клавиши вбок
       /* while(start->next)
        {
            make_line(start->x_coord,start->y_coord,start->next->x_coord,start->next->y_coord,start->mlx_ptr,start->win_ptr, 0xcd1076);
            start = start->next;
        }*/
       //make_web(5, 5, 50, mlx_ptr, win_ptr);
	}

	//mlx_key_hook(win_ptr, deal_key, ((void *)0));
	//mlx_clear_window(mlx_ptr,win_ptr);//чистим окно
	//mlx_destroy_window(mlx_ptr,win_ptr);//уничтожаем окно
	//img_ptr = mlx_new_image(mlx_ptr, 100, 100);
	//data_ptr = mlx_get_data_addr(img_ptr, bits, size_line, endian);
	//printf("data_ptr is: %s\n", data_ptr);

	mlx_loop(mlx_ptr);//без него ничего не работает

	return (0);
}

