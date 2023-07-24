/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:41:42 by amatta            #+#    #+#             */
/*   Updated: 2023/07/24 15:55:08 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(t_game *game)
{
	game->map_height = 0;
	while (game->map[game->map_height] != NULL)
		game->map_height++;
	return (game->map_height);
}

int	map_width(t_game *game)
{
	game->map_width = 0;
	game->map_width = ft_strlen(game->map[0]);
	return (game->map_width);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
}

void	init_struct(t_game *game)
{
	game->map_width = map_width(game);
	game->map_height = map_height(game);
	game->player_count = 0;
	game->collect_count = 0;
	game->count_collect = 0;
	game->enemy_count = 0;
	game->exit_count = 0;
	game->img_pxl = 64;
	game->p_x = 0;
	game->p_y = 0;
	game->e_x = 0;
	game->e_y = 0;
	game->n_y = 0;
	game->n_x = 0;
}
