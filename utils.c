/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:57:43 by amatta            #+#    #+#             */
/*   Updated: 2023/07/31 15:42:23 by amatta           ###   ########.fr       */
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

void	print_move(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->p_moves);
	mlx_string_put(game->mlx, game->win, 32, 32, 0xa832a2, "MOVES:");
	mlx_string_put(game->mlx, game->win, 80, 32, 0xa832a2, moves);
	free(moves);
}
