/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:56:38 by jslave            #+#    #+#             */
/*   Updated: 2019/09/19 15:16:08 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			clean_lst(t_list *begin)
{
	t_list *temp;

	while (begin->next)
	{
		temp = begin->next;
		free(begin);
		begin = temp;
	}
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *begin;

	if (!lst || !f)
		return (NULL);
	fresh = f(lst);
	begin = fresh;
	while (lst->next)
	{
		lst = lst->next;
		if (!(fresh->next = f(lst)))
		{
			clean_lst(begin);
			return (NULL);
		}
		fresh = fresh->next;
	}
	return (begin);
}
