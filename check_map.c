/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:28:56 by amatta            #+#    #+#             */
/*   Updated: 2023/07/21 17:30:02 by amatta           ###   ########.fr       */
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
			error("Invalid map boundary. Only 1s are allowed.");
		i++;
	}
	i = 0;
	while (i < map_height(game))
	{
		if (game->map[i][0] != '1' || game->map[i][map_width(game) - 1] != '1')
			error("Invalid map boundary. Only 1s are allowed.");
		i++;
	}
}

void	check_inner_map(t_game *game)
{
	int		i;
	int		j;
	char	current_cell;

	i = 1;
	while (i < game->map_height - 1)
	{
		j = 1;
		while (j < game->map_width - 1)
		{
			current_cell = game->map[i][j];
			if (current_cell != '0' && current_cell != '1'
				&& current_cell != 'C' && current_cell != 'P'
				&& current_cell != 'E')
				error("Invalid map cell.");
			if (current_cell == 'C')
				game->collect_count += 1;
			if (current_cell == 'P')
				game->player_count += 1;
			if (current_cell == 'E')
				game->exit_count += 1;
			j++;
		}
		i++;
	}
}

void	check_items(t_game *game)
{
	if (game->player_count >= 2)
		error("Only one player is accepted!");
	if (!game->player_count)
		error("Missing Player!");
	if (!game->collect_count)
		error("Missing Collectible!");
	if (!game->exit_count)
		error("Missing exit!");
}

void	check_map(t_game *game)
{
	check_walls(game);
	check_inner_map(game);
	check_items(game);
}
