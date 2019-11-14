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
    *y = previous_x * sin(fdf->z_rotate) + previous_y * cos(fdf->z_rotate);

    fdf->z_rotate+=(0.00001);
}

void iso(int *x, int *y, int *z)
{
    int previous_x;
    int previous_y;
    int previous_z;

    previous_z = *z;
    previous_x = *x;
    previous_y = *y;
   *x = (previous_x - previous_y) * cos(0.523599);
   *y = -previous_z + (previous_x + previous_y) * sin(0.523599);

}


void    change_points(int *x, int *y, int *z, t_fdf *fdf)
{
   if (fdf->dimension == 'x')
        x_rotate(y, z, fdf);
    if (fdf->dimension == 'y')
        y_rotate(x, z, fdf);
    if (fdf->dimension == 'z')
        z_rotate(x, y, fdf);
    if (fdf->projection == 'i')
    {
        iso(x, y, z);
    }

}
