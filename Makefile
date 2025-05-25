# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 14:57:13 by amatta            #+#    #+#              #
#    Updated: 2024/01/09 11:54:43 by amatta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = main.c read_map.c utils.c check_map.c errors.c render_map.c handle_key.c player_moves.c enemy_moves.c check_game.c get_position.c exit_animation.c free_memory.c init.c flood_fill.c

LIBFT = ./libft/libft.a

FT_PRINTF = ./ft_printf/libftprintf.a

MINI = mlx_linux/libmlx.a

OBJS = $(SRCS:.c=.o)

all : $(LIBFT) $(FT_PRINTF) $(MINI) $(NAME)

$(MINI) : mlx_linux/
		make -C mlx_linux

$(LIBFT) : libft/
		make -C libft

$(FT_PRINTF) : ft_printf/
		make -C ft_printf

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $(SRCS)

clean :
	make clean -C ./libft
	make clean -C ./ft_printf
	make clean -C ./mlx_linux
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
