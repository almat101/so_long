/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:31:56 by amatta            #+#    #+#             */
/*   Updated: 2023/07/21 17:20:50 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_map(game);
	free(game->mlx);
	exit(1);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_win(game);
	if (keycode == 65362 || keycode == 119)
		player_up(game);
	if (keycode == 65364 || keycode == 115)
		player_down(game);
	if (keycode == 65361 || keycode == 97)
		player_left(game);
	if (keycode == 65363 || keycode == 100)
		player_right(game);
	return (0);
}
