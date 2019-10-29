/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:03:24 by jslave            #+#    #+#             */
/*   Updated: 2019/09/17 19:06:05 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *p;
	t_list *save;

	if (alst && *alst && del)
	{
		p = *alst;
		while (p)
		{
			save = (p->next);
			del((p->content), (p->content_size));
			free(p);
			p = save;
		}
		*alst = NULL;
	}
}
