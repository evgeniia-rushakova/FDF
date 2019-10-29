/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:15:33 by jslave            #+#    #+#             */
/*   Updated: 2019/09/19 11:26:53 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			qual_of_spaces(char *s)
{
	int		i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && (*s != '\0'))
	{
		i++;
		s++;
	}
	if (*s == '\0')
		return (i);
	s += (len - 1 - i);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && len != 0)
	{
		s--;
		i++;
		len--;
	}
	return (i);
}

char				*ft_strtrim(const char *s)
{
	char		*res;
	size_t		sp;
	size_t		i;

	i = 0;
	res = NULL;
	if (s)
	{
		if ((sp = qual_of_spaces((char *)s)) == ft_strlen((char *)s))
			return (ft_strnew(0));
		if (ft_strlen((char *)s) - (sp + 1) != 0)
			if ((res = ft_strnew(ft_strlen((char *)s) - sp)))
			{
				sp = ft_strlen((char *)s) - sp;
				while (*s == ' ' || *s == '\n' || *s == '\t')
					s++;
				while (*s != '\0' && sp > 0)
				{
					res[i++] = (char)(*s);
					s++;
					sp--;
				}
			}
	}
	return (res);
}
