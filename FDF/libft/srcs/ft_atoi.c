/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:59:45 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:13:26 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_return(unsigned long long int res, long long int neg)
{
	if (res >= 9223372036854775807 && neg == 1)
		return (-1);
	if (res >= 9223372036854775807 && neg == -1)
		return (0);
	return (res * neg);
}

int				ft_atoi(const char *str)
{
	int				i;
	long long int	result;
	long long int	neg;

	result = 0;
	i = 0;
	neg = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (ft_return(result, neg));
}
