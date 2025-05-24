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

void	init_struct(t_game *game)
{
	game->map_width = 0;
	game->map_height = 0;
	game->player_count = 0;
	game->collect_count = 0;
	game->exit_count = 0;
	game->enemy_count = 0;
	game->count_collect = 0;
	game->img_pxl = 64;
	game->p_x = 0;
	game->p_y = 0;
	game->e_x = 0;
	game->e_y = 0;
	game->p_moves = 0;
	game->p_direction = 1;
	game->frame = -1;
	game->cords = NULL;
	init_struct2(game);
}

void	init_struct2(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->player_left = NULL;
	game->player_right = NULL;
	game->collect = NULL;
	game->enemy = NULL;
	game->exit1 = NULL;
	game->exit2 = NULL;
	game->exit3 = NULL;
	game->zero = NULL;
	game->one = NULL;
}

void	print_move(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->p_moves);
	mlx_string_put(game->mlx, game->win, 32, 32, 0xa832a2, "MOVES:");
	mlx_string_put(game->mlx, game->win, 80, 32, 0xa832a2, moves);
	free(moves);
}
