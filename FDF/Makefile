# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 17:41:03 by tollivan          #+#    #+#              #
#    Updated: 2019/10/26 17:36:44 by tollivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libft

INCLUDES = libft/includes

MLX_LIB_INCLUDES = minilib

FLAGS = -Wall -Werror -Wextra -g

FLAGS_GRAPHIC = -framework OpenGL -framework Appkit

SRC = main.c

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