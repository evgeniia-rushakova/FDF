/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:28:58 by jslave            #+#    #+#             */
/*   Updated: 2019/11/15 16:43:25 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void        print_map(t_fdf *lst)
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
}

void        print_color_map(t_fdf *lst)
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
}
*/
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

void	arr_free(int **arr, int rows)
{
    int i;

    i = 0;
    while (i < rows)
    {
        free(arr[i]);
        i++;
    }
}

void        free_fdf(t_fdf *fdf)
{
    arr_free(fdf->map, fdf->rows);
    arr_free(fdf->color, fdf->rows);
}