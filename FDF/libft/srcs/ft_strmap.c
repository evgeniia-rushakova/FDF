/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:31:07 by jslave            #+#    #+#             */
/*   Updated: 2019/09/18 12:39:57 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*str;
	size_t		len;
	size_t		j;

	j = 0;
	if (s && f)
	{
		len = ft_strlen((char *)s);
		str = ft_strnew(len);
		if (!s || !f || str == NULL)
			return (NULL);
		while (s[j] != '\0')
		{
			str[j] = (*f)((char)s[j]);
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
