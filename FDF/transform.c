/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:26:52 by jslave            #+#    #+#             */
/*   Updated: 2019/11/14 14:37:16 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void x_rotate(int *y, int *z, t_fdf *fdf)//num0
{
    int previous_y;

    previous_y = *y;
    *y = previous_y * cos(fdf->x_rotate) + *z * sin(fdf->x_rotate);
    *z = (-previous_y) * sin(fdf->x_rotate) + *z * cos(fdf->x_rotate);
}

void y_rotate(int *x,int *z, t_fdf *fdf)//num8
{
    int     previous_x;

    previous_x = *x;
    *x = (previous_x) * cos(fdf->y_rotate) + *z * sin(fdf->y_rotate);
    *z = (-previous_x)* sin(fdf->y_rotate) + *z * cos(fdf->y_rotate);
}

void z_rotate(int *x, int *y, t_fdf *fdf)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = previous_x * cos(fdf->z_rotate) - previous_y * sin(fdf->z_rotate);
    *y = previous_y * sin(fdf->z_rotate) + previous_y * cos(fdf->z_rotate);
}

void iso(int *x, int *y, int *z, t_fdf *fdf)
{
    int previous_x;
    int previous_y;

    (void)fdf;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -*z + (previous_x + previous_y) * sin(0.523599);
    *x+=WIDTH/2;
}



void    change_points(int *x, int *y, int *z, t_fdf *fdf)
{
    if (*z > 0 || *z < 0)
        *z += fdf->z_coeff;
    if (fdf->dimension == 'x')
        x_rotate(y, z, fdf);
    else if (fdf->dimension == 'y')
        y_rotate(x, z, fdf);
    else if (fdf->dimension == 'z')
        z_rotate(x, y, fdf);
    if (fdf->projection == 'i')
        iso(x, y, z, fdf);
    *x = *x + fdf->x_offset;
    *y = *y + fdf->y_offset;
}

