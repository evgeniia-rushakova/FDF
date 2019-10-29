/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:51:19 by jslave            #+#    #+#             */
/*   Updated: 2019/10/03 14:19:47 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if (!(ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
			return (NULL);
		while (s1[i] != '\0')
		{
			ptr[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			ptr[i] = s2[j];
			i++;
			j++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
