/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:50:43 by amatta            #+#    #+#             */
/*   Updated: 2023/07/31 15:59:59 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_exit_animation(t_game *game)
{
	if (game->collect_count == game->count_collect)
	{
		game->frame += 1;
		if (game->frame <= 5000)
			mlx_put_image_to_window(game->mlx, game->win, game->exit1,
				game->e_x * 64, game->e_y * 64);
		if (game->frame > 5000 && game->frame <= 10000)
			mlx_put_image_to_window(game->mlx, game->win, game->exit2,
				game->e_x * 64, game->e_y * 64);
		if (game->frame > 10000 && game->frame <= 15000)
			mlx_put_image_to_window(game->mlx, game->win, game->exit3,
				game->e_x * 64, game->e_y * 64);
		if (game->frame > 15000)
			game->frame = -1;
	}
	return (0);
}
