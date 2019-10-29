/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:18:53 by jslave            #+#    #+#             */
/*   Updated: 2019/09/18 12:22:13 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		find_len(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n > 0 && n < 10)
		return (len + 1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void			reverse(char *src, int num)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	j = find_len(num) - 1;
	if (j == 0)
		return ;
	while (i <= j)
	{
		c = src[i];
		src[i] = src[j];
		src[j] = c;
		i++;
		j--;
	}
}

static char			*check_validity(int n)
{
	int		min;
	char	*res;
	int		max;

	min = -2147483648;
	max = 2147483647;
	res = NULL;
	if (n <= min)
		return (res = ft_strdup("-2147483648"));
	if (n < min)
		return (res);
	if (n == 0)
	{
		res = ft_strdup("0");
		return (res);
	}
	if ((n > min && n < 0) || (n > 0 && n <= max))
		res = ft_strnew(find_len(n));
	return (res);
}

char				*ft_itoa(int n)
{
	char	*res;
	size_t	i;
	int		sign;
	size_t	len;

	res = check_validity(n);
	i = 0;
	len = find_len(n);
	if (res && n != -2147483648 && n != 0)
	{
		if ((sign = n) < 0)
		{
			res[i + len - 1] = '-';
			n = -n;
			len--;
		}
		while (i < len)
		{
			res[i++] = n % 10 + '0';
			n /= 10;
		}
		reverse(res, sign);
	}
	return (res);
}
