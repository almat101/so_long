/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:31:44 by amatta            #+#    #+#             */
/*   Updated: 2023/07/25 11:10:45 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move_u_d(t_game *game, int idx, int y, int x, int dir)
{
	int	new_y;
	
	new_y = y + dir;
	if (game->map[new_y][x] != '1'
		&& game->map[new_y][x] != 'C'
		&& game->map[new_y][x] != 'E'
		&& game->map[new_y][x] != 'N')
	{
		if (game->map[new_y][x] == 'P')
			instant_lose(game);
		game->map[y][x] = '0';
		game->map[new_y][x] = 'N';
		game->cords[idx].y = new_y;
	}
}

void	enemy_move_r_l(t_game *game, int idx, int y, int x, int dir)
{
	int	new_x;

	new_x = x + dir;
	if (game->map[y][new_x] != '1'
		&& game->map[y][new_x] != 'C'
		&& game->map[y][new_x] != 'E'
		&& game->map[y][new_x] != 'N')
	{
		if (game->map[y][new_x] == 'P')
			instant_lose(game);
		game->map[y][x] = '0';
		game->map[y][new_x] = 'N';
		game->cords[idx].x = new_x;
	}
}

void fill_enemy(t_game *game)
{
	int idx;
	
	idx = 0;
	int y = 0;
	while (y < game->map_height) {
		int x = 0;
		while (x < game->map_width) {
			if (game->map[y][x] == 'N') {
				game->cords[idx].y = y;
				game->cords[idx].x = x;
				idx++;
			}
			x++;
		}
		y++;
	}
}

void select_enemy(t_game *game)
{
	int		idx;
	int		dir;

	dir	= rand() % 4;
	if(game->enemy_count > 0) {
		idx = rand() % game->enemy_count;
		if (dir == 0)
			enemy_move_u_d(game, idx, game->cords[idx].y, game->cords[idx].x, 1);
		else if (dir == 1)
			enemy_move_u_d(game, idx,  game->cords[idx].y, game->cords[idx].x, -1);
		else if (dir == 2)
			enemy_move_r_l(game, idx, game->cords[idx].y, game->cords[idx].x, 1);
		else
			enemy_move_r_l(game, idx,  game->cords[idx].y, game->cords[idx].x, -1);
	}
}