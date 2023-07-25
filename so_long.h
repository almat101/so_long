/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:31:40 by amatta            #+#    #+#             */
/*   Updated: 2023/07/25 16:04:02 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_game {
	int		map_width;
	int		map_height;
	int		player_count;
	int		collect_count;
	int		exit_count;
	int		enemy_count;
	int		count_collect;
	int		img_pxl;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		n_x;
	int		n_y;
	int		p_moves;
	int		p_direction;
	void	*mlx;
	void	*win;
	char	**map;
	void	*player_left;
	void	*player_right;
	void	*collect;
	void	*enemy;
	void	*exit;
	void	*zero;
	void	*one;
}				t_game;

char	**read_map(char *argv, t_game *game);
void	render_map(t_game *game);
void	draw_map(t_game *game);
void	draw_map2(t_game *game, int y, int x);
void	check_map(t_game *game);
void	check_walls(t_game *game);
void	check_items(t_game *game);
void	chek_inner_map(t_game *game);
void	init_struct(t_game *game);
int		map_height(t_game *game);
int		map_width(t_game *game);
char	*error(char *msg);
void	ft_free_map(t_game *game);
int		handle_key(int keycode, t_game *game);
int		close_win(t_game *game);
void	get_player(t_game *game);
void	get_enemy(t_game *game);
void	player_up(t_game *game);
void	player_down(t_game *game);
void	player_right(t_game *game);
void	player_left(t_game *game);
void	check_exit(t_game *game);
void	check_win(t_game *game);
void	get_exit(t_game *game);
void	put_exit(t_game *game);
void	check_lose(t_game *game);
void	enemy_right(t_game *game);
void	enemy_left(t_game *game);
void	enemy_up(t_game *game);
void	enemy_down(t_game *game);
void	print_move(t_game *game);
void	instant_lose(t_game *game);
#endif
