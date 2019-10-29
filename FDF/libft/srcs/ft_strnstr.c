/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:21:27 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:31:22 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_validity(const char *big, const char *lit, size_t l)
{
	size_t lenn;
	size_t lenn2;

	lenn2 = ft_strlen((char *)big);
	lenn = ft_strlen((char *)lit);
	if (lenn == 0)
		return (2);
	if (l != 0 && lenn2 != 0)
		return (1);
	return (0);
}

char				*ft_strnstr(const char *haystack, \
		const char *needle, size_t len)
{
	size_t	len2;

	len2 = ft_strlen((char *)needle);
	if (check_validity(haystack, needle, len) == 1)
	{
		while (*haystack != '\0' && len >= len2)
		{
			if (*haystack == *needle && ft_memcmp(haystack, needle, len2) == 0)
				return ((char *)haystack);
			haystack++;
			len--;
		}
	}
	else if (check_validity(haystack, needle, len) == 2)
		return ((char *)haystack);
	return (NULL);
}
