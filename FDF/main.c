/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:13:28 by jslave            #+#    #+#             */
/*   Updated: 2019/11/05 18:13:32 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib/mlx.h"

#include "libft/includes/libft.h"//поправить или минус 42
#include "fdf.h"

#include <stdio.h>
#include <math.h>



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

    //print_map(fdf);
    draw_all(fdf);
    mlx_hook(fdf->win_ptr,2, 0, key_press, fdf);//отлавливаем нажатие клавиш
    mlx_loop(fdf->mlx_ptr);

    //почистить фдф и массив
    return (0);
}
