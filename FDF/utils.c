/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:28:58 by jslave            #+#    #+#             */
/*   Updated: 2019/11/12 21:29:03 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int        print_map(t_fdf *lst)
{
    int        x;
    int        y;
    y = 0;
    while (y < lst->rows)
    {
        x = 0;
        while (x < lst->cols)
            printf("%d ", lst->map[y][x++]);
        printf("\n");
        y++;
    }
    return (0);
}
int        print_color(t_fdf *lst)
{
    int        x;
    int        y;
    y = 0;
    while (y < lst->rows)
    {
        x = 0;
        while (x < lst->cols)
            printf("%d ", lst->color[y][x++]);
        printf("\n");
        y++;
    }
    return (0);
}


void  erase_img(t_fdf *fdf)
{
    int i;

    i = 0;
    while(i != (WIDTH * HEIGHT)-1)
    {
        (fdf->img_data)[i] = 0x000000;
        i++;
    }
    mlx_put_image_to_window(fdf->mlx_ptr,fdf->win_ptr,fdf->img_ptr, 0, 0);
}



