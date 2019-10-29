/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushelem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:14:11 by jslave            #+#    #+#             */
/*   Updated: 2019/09/18 12:24:12 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstpushelem(t_list *begin, void const *content,\
		size_t content_size)
{
	t_list *begin_copy;
	t_list *new;

	if (begin)
	{
		begin_copy = begin;
		if (begin == NULL)
			return (NULL);
		while (begin->next)
			begin = begin->next;
		new = ft_lstnew(content, content_size);
		begin->next = new;
		new->next = NULL;
		return (begin_copy);
	}
	return (NULL);
}
