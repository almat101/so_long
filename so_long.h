/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:31:40 by amatta            #+#    #+#             */
/*   Updated: 2023/07/31 15:13:19 by amatta           ###   ########.fr       */
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
# include <time.h>

typedef struct {
    int y;
    int x;
} t_enemy_coords;


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
	// int		n_x;
	// int		n_y;
	t_enemy_coords *cords;
	int		p_moves;
	int		p_direction;
	int		frame;
	void	*mlx;
	void	*win;
	char	**map;
	void	*player_left;
	void	*player_right;
	void	*collect;
	void	*enemy;
	void	*exit1;
	void	*exit2;
	void	*exit3;
	void	*zero;
	void	*one;
}				t_game;

void	check_inner_map(t_game *game);
char	**read_map(char *argv, t_game *game);
void	render_map_1(t_game *game);
void	render_map_2(t_game *game);
void	draw_map(t_game *game);
void	draw_map2(t_game *game, int y, int x);
void	check_map(t_game *game);
void	check_walls(t_game *game);
void	check_items(t_game *game);
void	init_struct(t_game *game);
void	init_struct2(t_game *game);
int		map_height(t_game *game);
int		map_width(t_game *game);
void	ft_free_map(t_game *game);
int		handle_key(int keycode, t_game *game);
int		close_win(t_game *game);
void	get_player(t_game *game);
void	player_up_down(t_game *game, int dir);
void	player_right_left(t_game *game, int dir);
void	check_win(t_game *game);
void	get_exit(t_game *game);

void	print_move(t_game *game);
void	instant_lose(t_game *game);
int		put_exit_animation(t_game *game);
void	free_img(t_game *game);
void	is_dot_ber(char *argv);
void	ft_error(char *msg, char *str);
void	error(char *msg, t_game *game, int flag);
void	ft_error_mlx(char *msg, t_game *game);
void	mlx_init_game(t_game *game);
void	init_enemy_cords(t_game *game);
void	fill_enemy(t_game *game);
void	select_enemy(t_game *game);
void	enemy_move_u_d(t_game *game, int idx, int y, int x, int dir);
void	enemy_move_r_l(t_game *game, int idx, int y, int x, int dir);


#endif
