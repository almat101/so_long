/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:18:38 by amatta            #+#    #+#             */
/*   Updated: 2023/07/21 18:30:32 by amatta           ###   ########.fr       */
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
	ft_printf("YOU WIN!!!\n");
	exit(1);
}
