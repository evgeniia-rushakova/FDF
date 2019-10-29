/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:53:35 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:28:33 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (size <= (ft_strlen(dst)))
		return (ft_strlen((char *)src) + size);
	while (dst[i] != '\0' && i < size - 1)
		i++;
	while (*src && i < (size - 1))
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen((char *)src));
}
