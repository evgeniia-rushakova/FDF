/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:05:22 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:32:25 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t				lenn;

	lenn = ft_strlen((char *)needle);
	if (lenn == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			if (ft_strncmp(needle, haystack, lenn) == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
