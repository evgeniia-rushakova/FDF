/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:26:11 by jslave            #+#    #+#             */
/*   Updated: 2019/10/07 18:44:11 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list			*find_fd(t_list **start, int fdnum)
{
	t_list *begin;

	begin = *start;
	while (begin)
	{
		if ((begin->content_size) == ((size_t)fdnum))
			return (begin);
		begin = begin->next;
	}
	begin = (t_list*)malloc(sizeof(t_list));
	begin->content_size = (size_t)fdnum;
	begin->content = ft_strnew(0);
	ft_lstadd(start, begin);
	return (begin);
}

static char				*read_save(t_list *save, size_t lenofsave)
{
	char	*result;
	char	*temp;
	char	*test;
	size_t	len;

	result = NULL;
	if (save->content && (temp = ft_strchr((char *)save->content, '\n')))
	{
		result = ft_strsub((char *)save->content, 0, \
		(lenofsave - ft_strlen(temp)));
		test = ft_strdup(temp + 1);
		free(save->content);
		len = ft_strlen(test);
		save->content = ft_strnew(len);
		ft_strncpy(save->content, test, len);
		free(test);
	}
	else if (lenofsave != 0)
	{
		result = ft_strdup((char *)save->content);
		free((char *)save->content);
		save->content = NULL;
	}
	return (result);
}

static char				*read_buf(char *buf, t_list *save, int res)
{
	char		*result;
	size_t		lenofsave;

	result = NULL;
	if (res > 0)
		save->content = ft_strjoinfree(save->content, buf);
	lenofsave = ft_strlen((char *)save->content);
	if ((ft_strchr(save->content, '\n')))
		return (result = read_save(save, lenofsave));
	return (result);
}

int						get_next_line(int fd, char **line)
{
	int				res;
	char			buf[BUFF_SIZE + 1];
    static t_list 	*startsave;
	t_list			*save;
	size_t			lenofsave;

	if (fd < 0 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	save = find_fd(&startsave, fd);
	while ((res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		if ((*line = read_buf(buf, save, res)))
			return (1);
	}
	lenofsave = ft_strlen((char *)save->content);
	if (lenofsave == 0)
		return (0);
	if ((*line = read_save(save, lenofsave)))
		return (1);
	return (1);
}
