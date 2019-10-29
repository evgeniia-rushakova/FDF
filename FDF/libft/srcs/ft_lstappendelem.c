/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappendelem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:41:56 by jslave            #+#    #+#             */
/*   Updated: 2019/09/18 12:23:44 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstappendelem(t_list *start, t_list *new)
{
	t_list *nextel;
	t_list *save;

	if (start)
	{
		save = start;
		if (start && new)
		{
			nextel = start->next;
			start->next = new;
			new->next = nextel;
		}
		return (save);
	}
	return (NULL);
}
