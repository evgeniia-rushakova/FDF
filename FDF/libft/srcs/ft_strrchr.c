/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:26:23 by jslave            #+#    #+#             */
/*   Updated: 2019/09/09 17:38:31 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	char			*ps;
	char			*st;

	ps = (char *)s;
	st = (char *)s;
	ch = (unsigned char)c;
	while (*ps != '\0')
		ps++;
	if (ch == '\0')
		return (ps);
	else
	{
		while (*ps != ch && *ps != *st)
			ps--;
		if (*ps == ch)
			return (ps);
	}
	return (NULL);
}
