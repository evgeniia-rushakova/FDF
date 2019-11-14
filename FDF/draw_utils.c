/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:38:33 by jslave            #+#    #+#             */
/*   Updated: 2019/11/12 21:38:37 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_start
{
    int x;
    int y;
}               t_start;

t_bres     *create_bresenham_data(char type, int x_st, int y_st, t_fdf *fdf)
{
    t_bres *data;

    (void)fdf;
    (void)type;

    data = ft_memalloc(sizeof(t_bres));
    data->x_start = x_st;
    data->y_start = y_st;
    data->x_end = x_st;
    data->y_end = y_st;
    if (type =='x')
        data->x_end+=fdf->step;
    if (type == 'y')
        data->y_end+=fdf->step;
    return (data);
}

void       draw_all(t_fdf *fdf)//закинуть столбцы и строки
{
    int x_start = fdf->x_start;
    int y_start = fdf->y_start;
    int x;
    int y;
    t_bres *data;

    y = 0;
    while (y < fdf->rows)//y <= cols
    {
        x = 0;
        while (x < fdf->cols)//x <= rows
        {
            if (x + 1 < fdf->cols)
            {
                data = create_bresenham_data('x',x_start, y_start, fdf);
                data->z_start = (fdf->map[y][x]) * fdf->step;
                data->z_end = (fdf->map[y][x + 1]) * fdf->step;
                make_line(data, fdf);
            }
            if (y + 1 < fdf->rows)
            {
                data = create_bresenham_data('y',x_start,y_start, fdf);
                data->z_start = fdf->map[y][x] * fdf->step;
                data->z_end = fdf->map[y + 1][x] * fdf->step;
                make_line(data, fdf);
            }
            x_start+=fdf->step;
            x++;
        }
        x_start = fdf->x_start;
        y_start+=fdf->step;
        y++;
    }
    mlx_put_image_to_window(fdf->mlx_ptr,fdf->win_ptr,fdf->img_ptr,0,0);
}
