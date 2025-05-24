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
