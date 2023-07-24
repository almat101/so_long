/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:07:19 by amatta            #+#    #+#             */
/*   Updated: 2023/07/24 12:27:15 by amatta           ###   ########.fr       */
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
			if (game->map[y][x] == 'P')
			{
				game->p_y = y;
				game->p_x = x;
				break ;
			}
			x++;
		}
		y++;
	}
	get_exit(game);
	get_enemy(game);
}

void	get_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'E')
			{
				game->e_y = y;
				game->e_x = x;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	get_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'N')
			{
				game->n_y = y;
				game->n_x = x;
				break ;
			}
			x++;
		}
		y++;
	}
}
