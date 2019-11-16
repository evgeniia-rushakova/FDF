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
    if (keycode == 88)//num6  для поворота по Х
    {
        fdf->x_rotate += (0.1);
        fdf->dimension = 'x';
    }
    if (keycode == 86)//num4  для поворота по Х
    {
        fdf->x_rotate -= (0.1);
        fdf->dimension = 'x';
    }
    if (keycode == 91)//num8  для поворота по У
    {
        fdf->y_rotate+=(0.1);
       fdf->dimension = 'y';
    }
    if (keycode == 84)//num8  для поворота по У
    {
        fdf->y_rotate-=(0.1);
        fdf->dimension = 'y';
    }
    if (keycode == 83)//num1  для поворота по Z
    {
        fdf->z_rotate+=0.1;
       fdf->dimension = 'z';
    }
    if (keycode == 85)//num3  для поворота по Z
    {
        fdf->z_rotate+=0.1;
      fdf->dimension = 'z';
    }
    draw_all(fdf);
}

void    check_projection(int keycode, t_fdf *fdf)
{
    erase_img(fdf);
    if (keycode == 87)//num5
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
         fdf->y_rotate = 0;
         fdf->projection = 'i';
        }
    }
    draw_all(fdf);
}

void    check_change_size(int keycode, t_fdf *fdf)
{
    erase_img(fdf);
    if (keycode == 69)//num+
        fdf->resize+=1;
    if (keycode == 78 && fdf->resize -1 >=1)//num-
        fdf->resize-=1;
   if(keycode == 89 )//num7
       fdf->z_coeff-=2;
   if(keycode == 92)//num9
       fdf->z_coeff+=2;
    draw_all(fdf);
}

void    check_offset(int keycode, t_fdf *fdf)
{
    erase_img(fdf);
    if(keycode == 124)//стрелка вправо
        fdf->x_offset+=(fdf->cols/10);
    if(keycode == 125)//стрелка вниз
        fdf->y_offset+=(fdf->rows/10);
    if(keycode == 123)
        fdf->x_offset-=(fdf->cols/10);
    //стрелка влево
    if(keycode == 126)//стрелка вверх
        fdf->y_offset-=(fdf->rows/10);
    draw_all(fdf);
}

void    check_restore(int keycode, t_fdf *fdf)
{
    erase_img(fdf);
    if (keycode == 67)
    {
        fdf->x_offset = 0;
        fdf->y_offset = 0;
        fdf->x_rotate = 0;
        fdf->y_rotate = 0;
        fdf->z_rotate = 0;
        fdf->z_coeff = 0;
        fdf->resize = 1;
        fdf->step = 10;///DEL
       fdf->x_start = ((WIDTH  -  (fdf->cols * fdf->step))/2);
       fdf->y_start =((HEIGHT  -  (fdf->rows * fdf->step))/2);
    }
    draw_all(fdf);
}

int     key_press(int keycode, t_fdf *fdf)
{
    if(keycode == 53)//esc
    {
        //ft_memdel(fdf);
        exit(0);
    }
    check_offset(keycode,fdf);
    check_projection(keycode, fdf);
    check_rotates(keycode, fdf);
    check_change_size(keycode, fdf);
  check_restore(keycode, fdf);
    return (0);
}
