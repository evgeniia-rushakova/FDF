/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:13:25 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:41:13 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		res;
	size_t	i;
	size_t	len;

	i = 0;
	res = 0;
	if (s1 && s2)
	{
		if (n == 0)
			return (1);
		len = ft_strlen((char *)s1);
		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && i <= n - 1)
		{
			s1++;
			s2++;
			i++;
		}
		if (*s1 == '\0' && *s2 == '\0')
			res = 1;
		if (i == n)
			res = 1;
	}
	return (res);
}
