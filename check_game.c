/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale <ale@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:18:38 by amatta            #+#    #+#             */
/*   Updated: 2023/07/24 00:49:48 by ale              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_game *game)
{
	int	x;
	int	y;

	if (game->collect_count == game->count_collect)
	{
		y = 0;
		while (y < game->map_height)
		{
			x = 0;
			while (x < game->map_width)
			{
				if (game->map[y][x] == 'E')
				{
					mlx_put_image_to_window(game->mlx, game->win, game->exit,
						x * 128, y * 128);
				}
				x++;
			}
			y++;
		}
	}
}

void	check_win(t_game *game)
{
	int	x;
	int	y;

	if (game->collect_count == game->count_collect)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit, game->e_x * 128, game->e_y * 128);
		if (game->p_x == game->e_x && game->p_y == game->e_y)
		{
			ft_printf("\nYOU WIN!\n");
			exit(1);
			//close_win(game);
		}
	}
}
