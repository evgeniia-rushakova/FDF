/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:30:14 by jslave            #+#    #+#             */
/*   Updated: 2019/10/21 18:20:08 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/*
int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (ps1[i] == ps2[i] && ps1[i] != '\0' && ps2[i] != '\0')
		i++;
	return (ps1[i] - ps2[i]);
}*/
int		ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    if (*s1 == *s2)
        return (0);
    return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
