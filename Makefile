# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatta <amatta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 14:57:13 by amatta            #+#    #+#              #
#    Updated: 2023/07/31 13:39:32 by amatta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = main.c read_map.c utils.c check_map.c errors.c render_map.c handle_key.c player_moves.c enemy_moves.c check_game.c get_position.c exit_animation.c

LIBFT = ./libft/libft.a

FT_PRINTF = ./ft_printf/libftprintf.a

MINI = mlx_linux/libmlx.a

OBJS = $(SRCS:.c=.o)

$(MINI) : mlx_linux/
		make -C mlx_linux

$(LIBFT) : libft/
		make -C libft
		make clean -C libft

$(FT_PRINTF) : ft_printf/
		make -C ft_printf
		make clean -C ft_printf

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $(SRCS)

all : $(LIBFT) $(FT_PRINTF) $(MINI) $(NAME)

clean :
	make clean -C libft
	make clean -C ft_printf
	rm -rf $(OBJS) $(LIBFT)

fclean:
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
