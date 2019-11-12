/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:26:26 by jslave            #+#    #+#             */
/*   Updated: 2019/11/12 21:26:38 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_press(int keycode, t_fdf *fdf)//закрывает окошко пр  нажатии клавиши еск.Возможно нужно переделать
{
    if (keycode == 89)//num7
    {
        erase_img(fdf);
        if (fdf->dimension == 'i')
            fdf->dimension = 'n';
        else if (fdf->dimension == 'n')
            fdf->dimension = 'i';
        draw_all(fdf);
    }
    if(keycode == 53)//esc
    {
        exit(0);
    }
    if(keycode == 124)//стрелка вправо
    {
        erase_img(fdf);
        fdf->x_start+=10;
        draw_all(fdf);
    }
    if(keycode == 126)//стрелка вниз
    {
        erase_img(fdf);
        fdf->y_start+=10;
        draw_all(fdf);
    }
    if(keycode == 123)//стрелка влево
    {
        erase_img(fdf);
        fdf->x_start-=10;
        draw_all(fdf);
    }
    if(keycode == 125)//стрелка вверх
    {
        erase_img(fdf);
        fdf->y_start-=10;
        draw_all(fdf);
    }
    if (keycode == 88)//num6  для поворота по Х
    {
        erase_img(fdf);
        fdf->dimension = 'x';
        draw_all(fdf);
        fdf->dimension = 'i';
    }
    if (keycode == 91)//num2  для поворота по У
    {
        erase_img(fdf);
        fdf->dimension = 'y';
        draw_all(fdf);
        fdf->dimension = 'i';
    }
    if (keycode == 87)//num5  для поворота по Z
    {
        erase_img(fdf);
        fdf->dimension = 'z';
        draw_all(fdf);
        fdf->dimension = 'i';
    }
    if (keycode == 69)//num+
    {
        erase_img(fdf);
        fdf->step+=5;
        draw_all(fdf);
    }
    if (keycode == 78)//num-
    {
        erase_img(fdf);
        if (fdf->step -=5 != 0)
            fdf->step-=5;
        draw_all(fdf);
    }
    return (0);
}
