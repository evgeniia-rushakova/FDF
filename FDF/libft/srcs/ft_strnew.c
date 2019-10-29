/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:03:14 by jslave            #+#    #+#             */
/*   Updated: 2019/09/19 11:35:55 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = NULL;
	if (!(size + 1))
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		while (i != size)
		{
			str[i] = '\0';
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
