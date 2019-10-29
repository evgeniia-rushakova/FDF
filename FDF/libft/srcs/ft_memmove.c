/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:38:28 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:19:19 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*psrc;
	unsigned char		*pdst;
	size_t				i;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (psrc == pdst)
		return (dst);
	if (psrc < pdst)
	{
		i = len;
		while (i-- > 0)
			pdst[i] = psrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (dst);
}
