/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:21:20 by mgrass            #+#    #+#             */
/*   Updated: 2019/11/15 16:36:08 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error_out(void)
{
    ft_putendl("error1");
    ///freee mlx destroy
    exit(1);
}

int			check_color(char *line)
{
	int		count;

	count = 0;
	line++;
	if (*line && *line != '0')
		error_out();
	line++;
	if (*line && *line != 'x')
		error_out();
	line++;
	count += 2;
	while (*line && *line != ' ')
	{
		if ((*line < 'A' || *line > 'F') && (*line < 'a' || *line > 'f') &&
		(*line < '0' || *line > '9'))
			error_out();
		line++;
		count++;
	}
	if (count != 8 && count != 6 && count != 4) // какие цвета еще могут быть? 0xff 0xff00
		error_out();
	return (count);
}

void		check_line(char *line)
{
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (*line == '-')
			line++;
		if (*line < '0' || *line > '9')
			error_out();
		while (*line != '\0' && *line >= '0' && *line <= '9')
			line++;
		if (*line == ',')
			line += check_color(line) + 1;
		if (*line && *line != ' ')
			error_out();
		while (*line && *line == ' ')
			line++;
	}
}

int			check_size(t_fdf *lst, char *line)
{
	char	**tmp;
	int		x;

	x = 0;
	check_line(line);
	tmp = ft_strsplit(line, ' ');
	while (tmp[x])
		free(tmp[x++]);
	if (lst->rows == 0)
		lst->cols = x;
	else
	{
		if (x != lst->cols)
			return (0);
	}
	free(line);
	free(tmp);
	lst->rows++;
	return (1);
}

void		create_color_map(char *tmp, t_fdf *lst, int x, int y)
{
	char	**ptr;

	ptr = ft_strsplit(tmp, ',');
	if (ptr[1])
	{
		lst->color[y][x] = ft_atoi_base(ptr[1] + 2, 16);
		free(ptr[1]);
	}
	else 
		lst->color[y][x] = 1;
	free(ptr[0]);
	free(ptr);
	// фри фри фри i want to break free
}

void		create_map(t_fdf *lst)
{
	char	*line;
	char	**tmp;
	int		x;
	int		y;

	lst->z_max = 0;
	lst->z_min = 0;
	y = 0;
	while ((get_next_line(lst->fd, &line)) == 1)
	{
		x = 0;
		tmp = ft_strsplit(line, ' ');
		lst->map[y] = ft_memalloc(sizeof(int) * lst->cols);
		lst->color[y] = ft_memalloc(sizeof(int) * lst->cols);
		// printf("-----\n");
		while (tmp[x])
		{
			create_color_map(tmp[x], lst, x, y);
			lst->map[y][x] = ft_atoi(tmp[x]);
			if (lst->map[y][x] > lst->z_max)
                 lst->z_max = lst->map[y][x];
            if (lst->map[y][x] < lst->z_min)
                 lst->z_min = lst->map[y][x];
			// create_color(lst, x, y, lst->map[y][x]);
			create_color(lst, x, y);
			free(tmp[x++]);
		}
		free(tmp);
		y++;
	}
}



t_fdf		*read_file(char *s)
{
	t_fdf	*fdf;
	char	*line;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		error_out();

    fdf->cols = 0;
    fdf->rows = 0;
    fdf->step = 0;
	fdf->name = s;
	fdf->dimension = 'n';
	fdf->x_offset = 0;
	fdf->y_offset = 0;
    fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "little_cat");
    fdf->img_ptr = mlx_new_image(fdf->mlx_ptr,WIDTH, HEIGHT);
    fdf->img_data = (int *)mlx_get_data_addr(fdf->img_ptr, &(fdf->bpp), &(fdf->size_line), &(fdf->endian));
	if ((fdf->fd = open(s, O_RDONLY)) < 0)
		error_out();
	while ((get_next_line(fdf->fd, &line)) == 1)
	{
		if (!(check_size(fdf, line)))
			error_out();
	}
	fdf->resize = 1;
	fdf->step = 5;
	fdf->x_start = ((WIDTH  -  (fdf->cols * fdf->step*fdf->resize))/2);
    fdf->y_start = ((HEIGHT  -  (fdf->rows * fdf->step*fdf->resize))/2);
	fdf->map = ft_memalloc(sizeof(int *) * fdf->rows);
	fdf->color = ft_memalloc(sizeof(int *) * fdf->rows);
	fdf->z_coeff = 0;
	close(fdf->fd);
	fdf->fd = open(fdf->name, O_RDONLY);
	return (fdf);
}
