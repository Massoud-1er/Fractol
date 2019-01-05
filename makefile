# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/05 13:08:40 by jdescler          #+#    #+#              #
#    Updated: 2019/01/05 14:17:23 by mmovahhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fractol

SRCS =	src/main.c\
		src/print.c\
		src/error.c\
		src/image.c\
		src/bis.c\
		src/event.c\
		src/color.c\
		src/algo.c\
		src/algo2.c\
		src/thread.c\


OBJS = $(SRCS:.c=.o)

CC = gcc -g -O3 -Iincludes/

CFLAGS = -Wall -Werror -Wextra

MLX = -lmlx -framework OpenGL -framework AppKit -L ./minilibx_macos/

LIBFT = libft/libft.a

.PHONY: all lib clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@make clean -C libft
	-rm -f $(OBJS)

fclean:clean
	@make fclean -C ./libft/
	-rm -f $(NAME)

re: fclean all
