/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:13:28 by jslave            #+#    #+#             */
/*   Updated: 2019/11/15 16:39:16 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
    t_fdf   *fdf;

    if (ac != 2)
    {
        ft_putendl("usage: ./fdf file");
        exit(1);
    }
       if (!(fdf = read_file(av[1])))
           error_out();
    create_map(fdf);

    // print_map(fdf);
    // print_color_map(fdf);
    
    draw_all(fdf);
    mlx_hook(fdf->win_ptr,2, 0, key_press, fdf);//отлавливаем нажатие клавиш
    // print_menu(fdf);
    mlx_loop(fdf->mlx_ptr);
    // почистить фдф и массив

    return (0);
}
