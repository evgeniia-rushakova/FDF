/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:54:03 by jslave            #+#    #+#             */
/*   Updated: 2019/10/03 14:18:48 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*(char*)str == (char)c)
			return ((char*)str);
		str++;
	}
	if (*(char*)str == '\0' && c == '\0')
		return ((char*)str);
	return (NULL);
}
