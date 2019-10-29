/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:01:39 by jslave            #+#    #+#             */
/*   Updated: 2019/09/18 12:40:18 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*str;
	size_t			len;
	size_t			j;

	j = 0;
	if (s)
	{
		len = ft_strlen((char *)s);
		str = ft_strnew(len);
		if (!s || !f || str == NULL)
			return (NULL);
		while (s[j] != '\0')
		{
			str[j] = (*f)((unsigned int)j, (char)s[j]);
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
