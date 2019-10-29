/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:00:58 by jslave            #+#    #+#             */
/*   Updated: 2019/10/06 16:13:13 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void *mem;
	void *res;

	mem = malloc(size);
	if (mem)
	{
		res = mem;
		ft_memset(mem, '\0', size);
	}
	else
		return (NULL);
	return (res);
}
