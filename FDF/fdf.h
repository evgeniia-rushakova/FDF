/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:22:05 by mgrass            #+#    #+#             */
/*   Updated: 2019/11/11 15:12:02 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# include "minilib/mlx.h" // библиотека minilibx
# include "libft/includes/libft.h"
# include <math.h>
#include <mach/task_info.h>

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define WIDTH 1300
# define HEIGHT 1300

typedef struct      s_bres
{
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int z_start;
    int z_end;
    int x;
    int y;
    int dx;
    int dy;
    int dx1;
    int dy1;
    int px;
    int py;
    int xe;
    int ye;
}                   t_bres;

typedef struct		s_fdf
{
	char			*name;
	int				fd;
	int				cols;//x
	int				rows;//y
	int				**map;
	int				**color;
    char                dimension;
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img_ptr;
    int                 *img_data;
    int                 step;
    int                 bpp;
    int                 endian;
    int                 size_line;
    int                 x_start;
    int                 y_start;
    double              x_rotate;
    double              y_rotate;
    double              z_rotate;
}					t_fdf;


void		print_menu(t_fdf *lst);
void		iso(int *x, int *y, int *z);
void		draw_line(int x, int y, int x1, int y1, t_fdf *lst);
void		draw_map(t_fdf *lst);
t_fdf		*read_file(char *s);
void		error_out(void);
void		error_out1(void);
void		error_out2(void);
void		create_map(t_fdf *lst);
void        erase_img(t_fdf *fdf);
//void        make_line(int x_start, int y_start, int x_end, int y_end, int *img_data, int color);
void        x_rotate(int *y, int *z, t_fdf *fdf);
void        y_rotate(int *x,int *z, t_fdf *fdf);
void        z_rotate(int *x, int *y, t_fdf *fdf);
void        make_horizontal_line(t_fdf *fdf, int x_start, int y_start, int z, int next_z);
void        make_vertical_line(t_fdf *fdf, int x_start, int y_start, int z, int next_z);
void       draw_all(t_fdf *fdf);
int         key_press(int keycode, t_fdf *fdf);
int         find_step(t_fdf *fdf);
void        change_points(int *x, int *y, int *z, t_fdf *fdf);

//
void make_line(t_bres *data, t_fdf *fdf);
void    draw_dx(t_bres *data, t_fdf *fdf);
void    draw_dy(t_bres *data, t_fdf *fdf);

#endif
