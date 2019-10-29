/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:50:09 by jslave            #+#    #+#             */
/*   Updated: 2019/10/04 19:06:39 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoinfree(char *s1, char *s2)
{
	char		*ptr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}
