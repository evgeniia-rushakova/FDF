/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:45:45 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:17:49 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			i;

	i = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (ps1 == ps2 || n == 0)
		return (0);
	while (*ps1 == *ps2 && i < n - 1)
	{
		ps1++;
		ps2++;
		i++;
	}
	if (i-- == n--)
	{
		ps1--;
		ps2--;
	}
	return (*ps1 - *ps2);
}
