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
    *y = (previous_y - HEIGHT/2) * cos(fdf->x_rotate) + *z * sin(fdf->x_rotate);
    *y+= HEIGHT/2;
    *z = (-previous_y + HEIGHT/2) * sin(fdf->x_rotate) + *z * cos(fdf->x_rotate);
}

void y_rotate(int *x,int *z, t_fdf *fdf)//num8
{
    int     previous_x;

    previous_x = *x;
    *x = (previous_x -WIDTH/2) * cos(fdf->y_rotate) + *z * sin(fdf->y_rotate);
    *x+=WIDTH/2;
    *z = (-previous_x + WIDTH/2)* sin(fdf->y_rotate) + *z * cos(fdf->y_rotate);
}


void iso(int *x, int *y, int *z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -*z + (previous_x + previous_y) * sin(0.523599);
    *x+=WIDTH/2;
}

void    change_points(int *x, int *y, int *z, t_fdf *fdf)
{
    x_rotate(y, z, fdf);
    y_rotate(x, z, fdf);
    if (fdf->projection == 'i')
        iso(x, y, z);
   *x += fdf->x_offset;
   *y += fdf->y_offset;
}

