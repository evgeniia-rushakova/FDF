/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:26:26 by jslave            #+#    #+#             */
/*   Updated: 2019/11/13 18:34:56 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    check_rotates(int keycode, t_fdf *fdf)
{
    erase_img(fdf);
    if (keycode == KEY_NUM6)//num6  для поворота по Х
        fdf->x_rotate += (0.1);
    if (keycode == KEY_NUM4)//num4  для поворота по Х
        fdf->x_rotate -= (0.1);
    if (keycode == KEY_NUM8)//num8  для поворота по У
        fdf->y_rotate+=(0.1);
    if (keycode == KEY_NUM2)//num2  для поворота по У
        fdf->y_rotate-=(0.1);
    draw_all(fdf);
}

void    check_projection(int keycode, t_fdf *fdf)
{
    erase_img(fdf);
    if (keycode == KEY_NUM5)//num5
    {
        if (fdf->projection == 'i')
        {
            fdf->projection = 'n';
            fdf->x_rotate = 0;
            fdf->y_rotate = 0;
        }
        else if (fdf->projection != 'i')
        {
         fdf->x_rotate = 0;
         fdf->y_rotate =0;
         fdf->projection = 'i';
        }
    }
    draw_all(fdf);
}

void    check_change_size(int keycode, t_fdf *fdf)
{
    erase_img(fdf);
    if (keycode == KEY_NUM_P)//num+
        fdf->resize+=1;
    if (keycode == KEY_NUM_M && fdf->resize -1 >=1)//num-
        fdf->resize-=1;
   if(keycode == KEY_NUM7)//num7
       fdf->z_coeff += 20;
   else if(keycode == KEY_NUM9)//num9
       fdf->z_coeff-=20;
    draw_all(fdf);
   fdf->z_coeff = 0;
}

void    check_offset(int keycode, t_fdf *fdf)
{
    erase_img(fdf);
    if(keycode == KEY_RIGHT)//стрелка вправо
        fdf->x_offset+=(fdf->cols/10);
    if(keycode == KEY_DOWN)//стрелка вниз
        fdf->y_offset+=(fdf->rows/10);
    if(keycode == KEY_LEFT)
        fdf->x_offset-=(fdf->cols/10);
    //стрелка влево
    if(keycode == KEY_UP)//стрелка вверх
        fdf->y_offset-=(fdf->rows/10);
    draw_all(fdf);
}

void    check_restore_and_color(int keycode, t_fdf *fdf)
{
    erase_img(fdf);
    if (keycode == KEY_AST)
    {
        fdf->x_offset = 0;
        fdf->y_offset = 0;
        fdf->x_rotate = 0;
        fdf->y_rotate = 0;
        fdf->z_coeff = 0;
        fdf->resize = 1;
        fdf->step = 20;///DEL
       fdf->x_start = ((WIDTH  -  (fdf->cols * fdf->step) + MENU_WIDTH)/2);
       fdf->y_start =((HEIGHT  -  (fdf->rows * fdf->step))/2);
    }
    if (keycode == KEY_NUM0)
        change_color(fdf);
    draw_all(fdf);
}

int     key_press(int keycode, t_fdf *fdf)
{
    if(keycode == KEY_ESC)
        exit(0);
    check_offset(keycode,fdf);
    check_projection(keycode, fdf);
    check_rotates(keycode, fdf);
    check_change_size(keycode, fdf);
    check_restore_and_color(keycode, fdf);
    return (0);
}
