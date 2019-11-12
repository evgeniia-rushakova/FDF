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
    int xe;

    if (data->dx >=0)
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
    fdf->img_data[y * WIDTH + x] = 0xcdcd00;//color
    while (x < xe)
    {
        x+=1;
        if (data->px < 0)
            data->px = data->px + 2 * abs(data->dy);
        else
            {
                ((data->dx < 0 && data->dy < 0) || (data->dx > 0 && data->dy > 0)) ?  (y += 1) : (y -= 1);
                data->px = data->px + 2 * (abs(data->dy) - abs(data->dx));
        }
        fdf->img_data[y * WIDTH + x] = 0xcdcd00;//color
    }
}

void    draw_dx(t_bres *data, t_fdf *fdf)
{
    int x;
    int y;
    int ye;


    if (data->dy >= 0)
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
    fdf->img_data[y * WIDTH + x] = 0xcdcd00;//color
    while (y < ye)
    {
        y += 1;
        if (data->py <= 0)
            data->py = data->py + 2 * abs(data->dx);
        else
            {
            ((data->dx < 0 && data->dy < 0) || (data->dx > 0 && data->dy > 0)) ? (x += 1) : (x -= 1);
            data->py = data->py + 2 * (abs(data->dx) - abs(data->dy));
        }
        fdf->img_data[y * WIDTH + x] = 0xcdcd00;//color
    }
}


//void make_line(int x_start, int y_start, int x_end, int y_end, int *img_data, int color)
void make_line(t_bres *data, t_fdf *fdf)
{
    fdf->img_data[data->y_start * WIDTH + data->x_start] = 0xcdcd00;//color
    if (abs(data->dy) <= abs(data->dx))
    {

        change_points(&data->x_start,&data->y_start,&data->z_start,fdf);
        change_points(&data->x_end,&data->y_end,&data->z_end,fdf);
        draw_dx(data, fdf);
    }
    else
        {
        change_points(&data->x_start,&data->y_start,&data->z_start,fdf);
        change_points(&data->x_end,&data->y_end,&data->z_end,fdf);
        draw_dy(data, fdf);
        }
    free(data);
}

/*
void make_line(int x_start, int y_start, int x_end, int y_end, int *img_data, int color)
{
    int x;
    int y;
    int dx;
    int dy;
    int dx1;
    int dy1;
    int px;
    int py;
    int xe;
    int ye;
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
        img_data[y * WIDTH + x] = 0xcdcd00;
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
            img_data[y * WIDTH + x] = color;
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
        img_data[y * WIDTH + x] = 0xcdcd00;
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
            img_data[y * WIDTH + x] = color;
        }
    }
}
*/