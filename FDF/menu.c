/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:04:56 by mgrass            #+#    #+#             */
/*   Updated: 2019/11/11 13:29:00 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_fdf *lst)
{
	int y = 0;

	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 10, y += 40, 16777215, "How to Use");
    mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "Change projection : Num5");
    mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "X_offset:  Right/Left");
    mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "Y_offset:  Up/Down");
    mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "Rotate X : Num6/Num4");
    mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "Rotate Y : Num8/Num2");
    mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "Rotate Z : Num1/Num3");
    mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "Resize: Num+/Num-");
    mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "Z-change: Num7/Num9");
    mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "Restore All: Num*");
}
