/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:26:47 by jslave            #+#    #+#             */
/*   Updated: 2019/10/03 14:17:39 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	if (!(ptr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
		ptr->next = NULL;
	}
	else
	{
		if (!(ptr->content = (char *)malloc(content_size)))
			return (NULL);
		ft_memcpy(ptr->content, content, content_size);
		ptr->content_size = content_size;
		ptr->next = NULL;
	}
	return (ptr);
}
