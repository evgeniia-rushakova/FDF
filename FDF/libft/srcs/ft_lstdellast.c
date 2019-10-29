/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:34:40 by jslave            #+#    #+#             */
/*   Updated: 2019/09/19 15:15:08 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstdellast(t_list *begin)
{
	t_list *begin_copy;
	t_list *save;

	if (begin)
	{
		begin_copy = begin;
		if (begin == NULL)
			return (NULL);
		while (begin->next)
		{
			save = begin;
			begin = begin->next;
		}
		free(begin);
		save->next = NULL;
		return (begin_copy);
	}
	return (NULL);
}
