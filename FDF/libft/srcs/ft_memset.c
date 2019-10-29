/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:17:58 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:19:46 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t count)
{
	unsigned char *ptr;

	if (count == 0)
		return (dest);
	ptr = (unsigned char *)dest;
	while (count > 0)
	{
		*ptr = (unsigned char)val;
		ptr++;
		count--;
	}
	return (dest);
}
