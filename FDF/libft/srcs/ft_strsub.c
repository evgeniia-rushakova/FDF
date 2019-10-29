/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:14:10 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 18:41:45 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (s)
	{
		res = ft_strnew(len);
		if (res == NULL)
			return (NULL);
		while (s[start] != '\0' && len != 0)
		{
			res[i] = (char)s[start];
			start++;
			i++;
			len--;
		}
		if (s[start] == '\0' && len != 0)
			return (NULL);
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
