# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 21:32:49 by jslave            #+#    #+#              #
#    Updated: 2019/11/13 14:13:51 by mgrass           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

LIBFT = libft

INCLUDES = libft/includes

MLX_LIB_INCLUDES = minilibx

FLAGS = -Wall -Wextra -Werror -g

FLAGS_GRAPHIC = -framework OpenGL -framework Appkit

SRC = main.c fdf.c keys.c utils.c transform.c bresenham.c draw_utils.c color.c menu.c

OUT = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OUT)
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(OUT) -L $(LIBFT) -lft -L $(MLX_LIB_INCLUDES) -lmlx $(FLAGS_GRAPHIC)
%.o: %.c
	gcc $(FLAGS) -I $(INCLUDES)  -o $@ -c $<

clean:
	/bin/rm -f $(OUT)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
