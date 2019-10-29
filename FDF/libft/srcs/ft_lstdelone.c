/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:48:33 by jslave            #+#    #+#             */
/*   Updated: 2019/09/19 15:22:17 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
	if (alst && *alst && del)
	{
		(*del)(((*alst)->content), ((*alst)->content_size));
		free(*alst);
		*alst = NULL;
	}
}
