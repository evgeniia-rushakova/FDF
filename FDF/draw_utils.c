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

/*
 void    make_horizontal_line(t_fdf *fdf, int x_start, int y_start, int z, int next_z)
{
    int y_end;
    int x_end;
    int temp_x;
    int temp_y;
    int temp_z;
    int temp_z_next;

    y_end = y_start;
    x_end =x_start + fdf->step;
    temp_x = x_start;
    temp_y = y_start;
    temp_z = z;
    temp_z_next = next_z;

    change_points(&x_end, &y_end, &temp_z_next, fdf);
    change_points(&temp_x, &temp_y, &temp_z, fdf);
    make_line(temp_x, temp_y, x_end,y_end, fdf->img_data,0xadff2f);
}

void    make_vertical_line(t_fdf *fdf, int x_start, int y_start, int z, int next_z)
{
    int y_end;
    int x_end;
    int temp_x;
    int temp_y;
    int temp_z;
    int temp_z_next;

    y_end = y_start + fdf->step;
    x_end =x_start;
    temp_x = x_start;
    temp_y = y_start;
    temp_z = z;
    temp_z_next = next_z;

    change_points(&x_end, &y_end, &temp_z_next, fdf);
    change_points(&temp_x, &temp_y, &temp_z, fdf);
    make_line(temp_x, temp_y, x_end, y_end, fdf->img_data,0x228b22);
}
*/
t_bres     *create_bresenham_data(int x_st, int y_st, int z_st, int z_end)
{
     t_bres *data;

     data = ft_memalloc(sizeof(t_bres));
     data->x_start = x_st;
     data->y_start = y_st;
     data->z_start = z_st;
     data->z_end = z_end;
     data->dx = data->x_end - data->x_start;
     data->dy = data->y_end -data->y_start;
     data->px = 2 * abs(data->dy) - abs(data->dx);
    data->py = 2 * abs(data->dx) - abs(data->dy);
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
                data = create_bresenham_data(x_start, y_start, fdf->map[y][x],fdf->map[y][x + 1]);
                data->x_end = data->x_start + fdf->step;
                data->y_end = data->y_start;
                make_line(data, fdf);
                //make_horizontal_line(fdf,x_start, y_start, fdf->map[y][x],fdf->map[y][x + 1]);
            }
            if (y + 1 < fdf->rows)
            {
                data = create_bresenham_data(x_start, y_start, fdf->map[y][x],fdf->map[y][x + 1]);
                data->x_end = data->x_start;
                data->y_end = data->y_start + fdf->step;
                make_line(data, fdf);
                //make_vertical_line(fdf,x_start,y_start,fdf->map[y][x],fdf->map[y + 1][x]);
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
