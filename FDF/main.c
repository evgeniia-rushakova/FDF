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

	mlx_ptr = mlx_init();//инициализируем

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
			printf("line is: %s\n", line);

		win_ptr = mlx_new_window(mlx_ptr, 500, 500, "little_cat");//создаем новое окно
		mlx_hook(win_ptr,2, 0, key_press, ((void *)0));//отлавливаем нажатие клавиш

		make_line(50, 50, 150, 50, mlx_ptr, win_ptr, 0x80);
		make_line(150, 50, 150, 150, mlx_ptr, win_ptr, 0x80);
		make_line(150, 150, 50, 150, mlx_ptr, win_ptr, 0x80);
		make_line(50, 150, 50, 50, mlx_ptr, win_ptr, 0x80);
        mlx_pixel_put(mlx_ptr,win_ptr,50,50,0xffdab9);
        mlx_pixel_put(mlx_ptr,win_ptr,150,50,0xffdab9);
        mlx_pixel_put(mlx_ptr,win_ptr,150,150,0xffdab9);
        mlx_pixel_put(mlx_ptr,win_ptr,50,150,0xffdab9);

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

