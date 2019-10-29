/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:36:47 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:30:22 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t count;

	count = 0;
	if (!src && !dst)
		return (NULL);
	while (src[count] != '\0' && count < len)
	{
		dst[count] = src[count];
		count++;
	}
	while (count < len)
	{
		dst[count] = '\0';
		count++;
	}
	return (dst);
}
