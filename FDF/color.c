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
