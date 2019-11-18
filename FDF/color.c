/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:42:53 by mgrass            #+#    #+#             */
/*   Updated: 2019/11/15 16:32:28 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(int x, int y, t_bres *point)
{
	int     red;
	int     green;
	int     blue;
	double  percentage;

	if (point->color_st == point->color_end)
		return (point->color_st);
	if (point->dx1 > point->dy1)
		percentage = percent(point->x_start, point->x_end, x);
	else
		percentage = percent(point->y_start, point->y_end, y);
	red = get_light((point->color_st >> 16) & 0xFF, (point->color_end >> 16) & 0xFF, percentage);
	green = get_light((point->color_st >> 8) & 0xFF, (point->color_end >> 8) & 0xFF, percentage);
	blue = get_light(point->color_st & 0xFF, point->color_end & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void    create_color(t_fdf *lst, int x, int y)
{
    int n = lst->map[y][x];
	
    if (lst->color[y][x] == 1 && n < 0)
		lst->color[y][x] = 0x00ceff;
    else if (lst->color[y][x] == 1 && n >= 0 && n < 10)
        lst->color[y][x] = 0x22f220;
    else if (lst->color[y][x] == 1 && n >= 10 && n < 20)
        lst->color[y][x] = 0x008FB3;
	else if (lst->color[y][x] == 1 && n >= 20 && n < 50)
        lst->color[y][x] = 0x20b2aa;
	else if (lst->color[y][x] == 1 && n >= 50 && n < 100)
        lst->color[y][x] = 0x33ff22;
	else if (lst->color[y][x] == 1 && n >= 100 && n < 500)
        lst->color[y][x] = 0x8fbc8f;
}

void        draw_background(t_fdf *fdf)
{
    int    i;
    i = 0;
    while (i < HEIGHT * WIDTH)
    {
        if (i % WIDTH < MENU_WIDTH)
            (fdf->img_data)[i] = 0x272727;
        else
            (fdf->img_data)[i] = 0x323232; // E5E5E5
        i++;
    }
}

void    change_color(t_fdf *fdf)
{
    int *palette;
    static int count = 0;
    int x;
    int y;

    palette = (int[22]){0x20b2aa ,0x98fb98,0x98fb98,0xff7f,0xff7f,0x7cfc00,
                        0x7cfc00,0xff00,0x7fff00,0xfa9a,0xfa9a,0xadff2f,
                        0xadff2f,0x32cd32,0x32cd32,0x9acd32,0x9acd32,0x228b22,
                        0x228b22,0x6b8e23,0x6b8e23,0xbdb76b};
    erase_img(fdf);
    y = 0;
    while (y < fdf->rows)
    {
        x = -1;
        while (x++ < fdf->cols)
        {
            fdf->color[y][x] = palette[count];
        }
        y++;
    }
    if (count == 21)
        count = -1;
    count++;
    draw_all(fdf);
}

