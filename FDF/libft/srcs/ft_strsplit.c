/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:24:29 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 19:59:11 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				qualw(char *s, char c)
{
	int i;
	int res;

	res = 0;
	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0' && *s != c)
		{
			res++;
			s++;
		}
		while (*s != c && *s != '\0')
			s++;
	}
	return (res);
}

static void				memfree(char **str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	*str = NULL;
}

static char				*get_new_word(char *s, char c)
{
	char	*word;
	int		len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	word = NULL;
	word = ft_memalloc(len + 1);
	if (word)
	{
		len = 0;
		while (*s != '\0' && *s != c)
			word[len++] = *s++;
		word[len] = '\0';
	}
	else
		return (NULL);
	return (word);
}

char					**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		k;
	int		i;

	i = 0;
	res = NULL;
	if (s == NULL)
		return (NULL);
	if ((res = (char **)malloc(sizeof(char *) * (qualw((char *)s, c) + 1))))
	{
		k = qualw((char *)s, c);
		while (i < k && *s)
		{
			while (*s == c && *s)
				s++;
			if (!(res[i] = get_new_word((char *)s, c)))
			{
				memfree(res, i);
				return (NULL);
			}
			s += (ft_strlen(res[i++]) + 1);
		}
		res[i] = NULL;
	}
	return (res);
}
