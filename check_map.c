/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:28:56 by amatta            #+#    #+#             */
/*   Updated: 2023/07/24 15:40:26 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < map_width(game))
	{
		if (game->map[0][i] != '1' || game->map[map_height(game) - 1][i] != '1')
			error("Invalid map boundary. Only 1s are allowed.", game, 1);
		i++;
	}
	i = 0;
	while (i < map_height(game))
	{
		if (game->map[i][0] != '1' || game->map[i][map_width(game) - 1] != '1')
			error("Invalid map boundary. Only 1s are allowed.", game, 1);
		i++;
	}
}

void	check_inner_map(t_game *game)
{
	int		i;
	int		j;

	i = 1;
	while (i < game->map_height - 1)
	{
		j = 1;
		while (j < game->map_width - 1)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'P'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'N' )
				error("Invalid map cell.", game, 1);
			if (game->map[i][j] == 'C')
				game->collect_count += 1;
			if (game->map[i][j] == 'N')
				game->enemy_count += 1;
			if (game->map[i][j] == 'P')
				game->player_count += 1;
			if (game->map[i][j] == 'E')
				game->exit_count += 1;
			j++;
		}
		i++;
	}
}

void	check_items(t_game *game)
{
	if (game->player_count >= 2)
		error("this game can handle only one player!", game, 1);
	if (game->enemy_count >= 2)
		error("this game can handle only one enemy!", game, 1);
	if (!game->player_count)
		error("missing player!", game, 1);
	if (!game->collect_count)
		error("missing collectible!", game, 1);
	if (!game->exit_count)
		error("missing exit!", game, 1);
}

void	check_map(t_game *game)
{
	check_walls(game);
	check_inner_map(game);
	check_items(game);
}
