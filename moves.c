/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:31:11 by amatta            #+#    #+#             */
/*   Updated: 2023/07/21 18:31:10 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if(game->map[y][x] == 'P')
				{
					game->p_y = y;
					game->p_x = x;
					break;
				}
			x++;
		}
		y++;
	}
}

void	player_up(t_game *game)
{
	int	new_y;

	get_player(game);
	new_y = game->p_y - 1;
	if (new_y >= 0 && game->map[new_y][game->p_x] != '1')
	{
		if (game->map[new_y][game->p_x] == 'C')
			game->count_collect++;
		game->map[game->p_y][game->p_x] = '0';
		game->map[new_y][game->p_x] = 'P';
		game->p_moves++;
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
		check_exit(game);
		ft_printf("Moves n°%d\n",game->p_moves);
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
			game->count_collect++;
		game->map[game->p_y][game->p_x] = '0';
		game->map[new_y][game->p_x] = 'P';
		game->p_moves++;
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
		check_exit(game);
		ft_printf("Moves n°%d\n",game->p_moves);
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
			game->count_collect++;
		game->map[game->p_y][game->p_x] = '0';
		game->map[game->p_y][new_x] = 'P';
		game->p_moves++;
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
		check_exit(game);
		ft_printf("Moves n°%d\n",game->p_moves);
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
			game->count_collect++;
		game->map[game->p_y][game->p_x] = '0';
		game->map[game->p_y][new_x] = 'P';
		game->p_moves++;
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
		check_exit(game);
		ft_printf("Moves n°%d\n",game->p_moves);
	}
}

