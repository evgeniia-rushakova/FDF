/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:36:14 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 20:47:14 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	i = 0;
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	while (i < n)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == (unsigned char)c)
			return (pdst + i + 1);
		i++;
	}
	return (NULL);
}
