/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:31:11 by amatta            #+#    #+#             */
/*   Updated: 2023/07/25 12:44:32 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_up(t_game *game)
{
	int	new_y;

	get_player(game);
	new_y = game->p_y - 1;
	if (game->map[new_y][game->p_x] != '1')
	{
		if (game->map[new_y][game->p_x] == 'C')
		{
			game->map[new_y][game->p_x] = '0';
			game->count_collect++;
		}
		game->map[game->p_y][game->p_x] = '0';
		enemy_left(game);
		if (game->map[new_y][game->p_x] == 'N')
			instant_lose(game);
		game->map[new_y][game->p_x] = 'P';
		game->p_y = new_y;
		game->p_moves++;
		draw_map(game);
		ft_printf("Moves n°%d\n", game->p_moves);
		check_lose(game);
		check_win(game);
	}
}

void	player_down(t_game *game)
{
	int	new_y;

	get_player(game);
	new_y = game->p_y + 1;
	if (game->map[new_y][game->p_x] != '1')
	{
		if (game->map[new_y][game->p_x] == 'C')
		{
			game->map[new_y][game->p_x] = '0';
			game->count_collect++;
		}
		game->map[game->p_y][game->p_x] = '0';
		enemy_right(game);
		if (game->map[new_y][game->p_x] == 'N')
			instant_lose(game);
		game->map[new_y][game->p_x] = 'P';
		game->p_moves++;
		game->p_y = new_y;
		draw_map(game);
		ft_printf("Moves n°%d\n", game->p_moves);
		check_lose(game);
		check_win(game);
	}
}

void	player_right(t_game *game)
{
	int	new_x;

	get_player(game);
	new_x = game->p_x + 1;
	if (game->map[game->p_y][new_x] != '1')
	{
		if (game->map[game->p_y][new_x] == 'C')
		{
			game->map[game->p_y][new_x] = '0';
			game->count_collect++;
		}
		game->map[game->p_y][game->p_x] = '0';
		enemy_up(game);
		if (game->map[game->p_y][new_x] == 'N')
			instant_lose(game);
		game->map[game->p_y][new_x] = 'P';
		game->p_moves++;
		game->p_x = new_x;
		draw_map(game);
		ft_printf("Moves n°%d\n", game->p_moves);
		check_lose(game);
		check_win(game);
	}
}

void	player_left(t_game *game)
{
	int	new_x;

	get_player(game);
	new_x = game->p_x - 1;
	if (game->map[game->p_y][new_x] != '1')
	{
		if (game->map[game->p_y][new_x] == 'C')
		{
			game->map[game->p_y][new_x] = '0';
			game->count_collect++;
		}
		enemy_down(game);
		if (game->map[game->p_y][new_x] == 'N')
			instant_lose(game);
		game->map[game->p_y][game->p_x] = '0';
		game->map[game->p_y][new_x] = 'P';
		game->p_moves++;
		game->p_x = new_x;
		draw_map(game);
		ft_printf("Moves n°%d\n", game->p_moves);
		check_lose(game);
		check_win(game);
	}
}
