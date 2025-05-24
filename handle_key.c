/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:31:56 by amatta            #+#    #+#             */
/*   Updated: 2023/07/31 15:58:29 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_win(game);
	if (keycode == 65362 || keycode == 119) {
		player_up_down(game, -1);
		select_enemy(game);
		
		// enemy_rand(game);
	}
	if (keycode == 65364 || keycode == 115) {
		player_up_down(game, 1);
		select_enemy(game);
		// enemy_rand(game);
	}
	if (keycode == 65361 || keycode == 97){
		player_right_left(game, -1);
		select_enemy(game);
		// enemy_rand(game);
	}
	if (keycode == 65363 || keycode == 100){
		player_right_left(game, 1);
		select_enemy(game);
		// enemy_rand(game);
	}
	return (0);
}
