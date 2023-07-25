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

void	enemy_up(t_game *game)
{
	int	new_y;

	if (game->enemy_count)
	{
		get_enemy(game);
		new_y = game->n_y - 1;
		if (game->map[new_y][game->n_x] != '1'
			&& game->map[new_y][game->n_x] != 'C'
			&& game->map[new_y][game->n_x] != 'E')
		{
			game->map[game->n_y][game->n_x] = '0';
			if (game->map[game->n_y][game->n_x] == 'P')
				instant_lose(game);
			if (game->map[new_y][game->n_x] == 'P')
				instant_lose(game);
			game->map[new_y][game->n_x] = 'N';
			game->n_y = new_y;
		}
	}
}

void	enemy_down(t_game *game)
{
	int	new_y;

	if (game->enemy_count)
	{
		get_enemy(game);
		new_y = game->n_y + 1;
		if (game->map[new_y][game->n_x] != '1'
		&& game->map[new_y][game->n_x] != 'C'
		&& game->map[new_y][game->n_x] != 'E')
		{
			game->map[game->n_y][game->n_x] = '0';
			if (game->map[game->n_y][game->n_x] == 'P')
				instant_lose(game);
			if (game->map[new_y][game->n_x] == 'P')
				instant_lose(game);
			game->map[new_y][game->n_x] = 'N';
			game->n_y = new_y;
		}
	}
}

void	enemy_right(t_game *game)
{
	int	new_x;

	if (game->enemy_count)
	{
		get_enemy(game);
		new_x = game->n_x + 1;
		if (game->map[game->n_y][new_x] != '1'
		&& game->map[game->n_y][new_x] != 'C'
		&& game->map[game->n_y][new_x] != 'E')
		{
			game->map[game->n_y][game->n_x] = '0';
			if (game->map[game->n_y][game->n_x] == 'P')
				instant_lose(game);
			if (game->map[game->n_y][new_x] == 'P')
				instant_lose(game);
			game->map[game->n_y][new_x] = 'N';
			game->n_x = new_x;
		}
	}
}

void	enemy_left(t_game *game)
{
	int	new_x;

	if (game->enemy_count)
	{
		get_enemy(game);
		new_x = game->n_x - 1;
		if (game->map[game->n_y][new_x] != '1'
		&& game->map[game->n_y][new_x] != 'C'
		&& game->map[game->n_y][new_x] != 'E')
		{
			game->map[game->n_y][game->n_x] = '0';
			if (game->map[game->n_y][game->n_x] == 'P')
				instant_lose(game);
			if (game->map[game->n_y][new_x] == 'P')
				instant_lose(game);
			game->map[game->n_y][new_x] = 'N';
			game->n_x = new_x;
		}
	}
}
