/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:42:59 by jslave            #+#    #+#             */
/*   Updated: 2019/10/04 17:16:53 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (p)
	{
		while (src[i] != '\0')
		{
			p[i] = src[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
