/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:56:55 by jslave            #+#    #+#             */
/*   Updated: 2019/11/12 21:56:57 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_dy(t_bres *data, t_fdf *fdf)
{
    int x;
    int y;
    int ye;

    if (data->dy >=0)
    {
        x = data->x_start;
        y = data->y_start;
        ye = data->y_end;
    }
    else
    {
        x = data->x_end;
        y = data->y_end;
        ye = data->y_start;
    }
        fdf->img_data[y * WIDTH + x] = 0xfff0f5;//color
    while (y < ye)
    {
        y+=1;
        if (data->py <= 0)
            data->py = data->py + 2 * data->dx1;
        else
            {
                ((data->dx < 0 && data->dy < 0) || (data->dx > 0 && data->dy > 0)) ?  (x++) : (x--);
                data->py = data->py + 2 * (data->dx1 - data->dy1);
        }
            fdf->img_data[y * WIDTH + x] = 0xdb7093;//color
    }
}

void    draw_dx(t_bres *data, t_fdf *fdf)
{
    int x;
    int y;
    int xe;

    if (data->dx >= 0)
    {
        x = data->x_start;
        y = data->y_start;
        xe = data->x_end;
    }
    else
        {
        x = data->x_end;
        y = data->y_end;
        xe = data->x_start;
    }
    if (y * WIDTH + x <= WIDTH * HEIGHT)
        fdf->img_data[y * WIDTH + x] =0xfff0f5;//color
    while (x < xe)
    {
        x += 1;
        if (data->px <= 0)
            data->px = data->px + 2 * data->dy1;
        else
            {
            ((data->dx < 0 && data->dy < 0) || (data->dx > 0 && data->dy > 0)) ? (y ++) : (y --);
            data->px = data->px + 2 * (data->dy1 - data->dx1);
        }
        if (y * WIDTH + x <= WIDTH * HEIGHT)
            fdf->img_data[y * WIDTH + x] = 0xff00ff;//color
    }
}


void make_line(t_bres *data, t_fdf *fdf)
{
    change_points(&data->x_start, &data->y_start, &data->z_start,fdf);
    change_points(&data->x_end, &data->y_end, &data->z_end,fdf);
    data->dx = data->x_end - data->x_start;
    data->dy = data->y_end -data->y_start;
    data->dx1 = abs(data->dx);
    data->dy1 = abs(data->dy);
    data->px = 2 * data->dy1 - data->dx1;
    data->py = 2 * data->dx1 - data->dy1;
    if (data->dy1 <= data->dx1)
        draw_dx(data, fdf);
    else
        draw_dy(data, fdf);
    free(data);
}
