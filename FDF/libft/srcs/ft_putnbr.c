/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:57 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:47:11 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int min;

	min = -2147483648;
	if (n == min)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else if (n >= 0 && n < 10)
		ft_putchar(n + '0');
}
