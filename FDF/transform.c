/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:26:52 by jslave            #+#    #+#             */
/*   Updated: 2019/11/12 21:26:54 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void x_rotate(int *y, int *z, t_fdf *fdf)//num0
{
    int previous_y;
    int previous_z;

    previous_z = *z;
    previous_y = *y;
    *y = previous_y * cos(fdf->x_rotate) + previous_z * sin(fdf->x_rotate);
    *z = -previous_y * sin(fdf->x_rotate) + previous_z * cos(fdf->x_rotate);
    fdf->x_rotate += (0.00001);
}

void y_rotate(int *x,int *z, t_fdf *fdf)
{
    int     previous_x;
    int     previous_z;

    previous_x = *x;
    previous_z = *z;
    *x = previous_x * cos(fdf->y_rotate) + previous_z * sin(fdf->y_rotate);
    *z = -previous_x * sin(fdf->y_rotate) + previous_z * cos(fdf->y_rotate);
    fdf->y_rotate+=(0.00001);
}

void z_rotate(int *x, int *y, t_fdf *fdf)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;

    *x = previous_x * cos(fdf->z_rotate) - previous_y * sin(fdf->z_rotate);
    *y = previous_y * sin(fdf->z_rotate) + previous_y * cos(fdf->z_rotate);

    fdf->z_rotate+=(0.00001);
}

void iso(int *x, int *y, int *z)
{
    int previous_x;
    int previous_y;
    int previous_z;

    previous_x = *x;
    previous_y = *y;
    previous_z = *z;
    *x = (previous_x - previous_y) * cos(0.523599);

    *y = -previous_z + (previous_x + previous_y) * sin(0.523599);

    //printf("old x: %i\n", previous_x );
    //printf("old y: %i\n", previous_y);
    //printf("new x: %i\n", *x);
    //printf("new y: %i\n", *y);
}

void    change_points(int *x, int *y, int *z, t_fdf *fdf)
{
    if (fdf->dimension == 'x')
        x_rotate(y, z, fdf);
    else if (fdf->dimension == 'y')
        y_rotate(x, z, fdf);
    else if (fdf->dimension == 'z')
        z_rotate(x, y, fdf);
    else if (fdf->dimension == 'i')
        iso(x, y, z);
}
