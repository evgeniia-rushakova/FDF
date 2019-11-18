/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:38:33 by jslave            #+#    #+#             */
/*   Updated: 2019/11/15 16:34:04 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bres     *create_offset_data(char type, int x_st, int y_st, t_fdf *fdf)
{
    t_bres *data;

    data = ft_memalloc(sizeof(t_bres));
    data->x_start = x_st;
    data->y_start = y_st;
    data->x_end = x_st;
    data->y_end = y_st;
    if (type =='x')
        data->x_end+=fdf->step*fdf->resize;
    else if (type == 'y')
        data->y_end+=fdf->step*fdf->resize;
    data->color_st = 0;
	data->color_end = 0;
    return (data);
}

/*
void        create_data_and_draw_x(t_fdf *fdf)
{
    int x;
    int y;
    int x_start;
    int y_start;
    t_bres *data;

    x_start = fdf->x_start;
    y_start= fdf->y_start;
    x = 0;
    y = 0;
    while (y < fdf->rows)//y <= cols
    {
        x = 0;
        while (x < fdf->cols)//x <= rows
        {
            if (x + 1 < fdf->cols)
            {
                data = create_offset_data('x',x_start, y_start,fdf);
                data->z_start = (fdf->map[y][x]) * fdf->step * fdf->resize;
                data->z_end = (fdf->map[y][x + 1]) * fdf->step * fdf->resize;
                data->color_st = fdf->color[y][x];
                data->color_end = fdf->color[y][x + 1];
                make_line(data, fdf);
            }
            x++;
        }
        x_start = fdf->x_start;
        y_start+=fdf->step * fdf->resize;
        y++;
    }
}

void        create_data_and_draw_y(t_fdf *fdf)
{
    int x;
    int y;
    int x_start;
    int y_start;

    x_start = fdf->x_start;
    y_start= fdf->y_start;
    x = 0;
    y = 0;
    while (y < fdf->rows)//y <= cols
    {
        x = 0;
        while (x < fdf->cols)//x <= rows
        {
            if (y + 1 < fdf->rows)
            {
                data = create_offset_data('y',x_start, y_start,fdf);
                data->z_start = fdf->map[y][x] * fdf->step*fdf->resize;
                data->z_end = fdf->map[y + 1][x] * fdf->step*fdf->resize;
                data->color_st = fdf->color[y][x];
                data->color_end = fdf->color[y + 1][x];
                make_line(data, fdf);
            }
            x++;
        }
        x_start = fdf->x_start;
        y_start+=fdf->step * fdf->resize;
        y++;
    }
}

*/

void       draw_all(t_fdf *fdf)//закинуть столбцы и строки
{
    int x_start = fdf->x_start;
    int y_start = fdf->y_start;
    int x;
    int y;
    t_bres *data;
    
    y = 0;
    draw_background(fdf);
    while (y < fdf->rows)//y <= cols
    {
        x = 0;
        while (x < fdf->cols)//x <= rows
        {
            if (x + 1 < fdf->cols)
            {
                //create_data_and_draw_x(fdf, );
                data = create_offset_data('x',x_start, y_start,fdf);
                data->z_start = (fdf->map[y][x]) * fdf->step*fdf->resize;
                data->z_end = (fdf->map[y][x + 1]) * fdf->step*fdf->resize;
				data->color_st = fdf->color[y][x];
				data->color_end = fdf->color[y][x + 1];
                make_line(data, fdf);
            }
            if (y + 1 < fdf->rows)
            {
                //create_data_and_draw_y();
                data = create_offset_data('y',x_start, y_start,fdf);
                data->z_start = fdf->map[y][x] * fdf->step*fdf->resize;
                data->z_end = fdf->map[y + 1][x] * fdf->step*fdf->resize;
				data->color_st = fdf->color[y][x];
				data->color_end = fdf->color[y + 1][x];
                make_line(data, fdf);
            }
            x_start+=fdf->step*fdf->resize;
            x++;
        }
        x_start = fdf->x_start;
        y_start+=fdf->step*fdf->resize;
        y++;
    }
    mlx_put_image_to_window(fdf->mlx_ptr,fdf->win_ptr,fdf->img_ptr,0,0);
    print_menu(fdf);
}


