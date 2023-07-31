/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:18:38 by amatta            #+#    #+#             */
/*   Updated: 2023/07/31 15:39:47 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win(t_game *game)
{
	if (game->count_collect == game->collect_count)
	{
		if (game->p_x == game->e_x && game->p_y == game->e_y)
		{
			ft_printf("\nYOU WIN!\n");
			close_win(game);
		}
	}
}

void	check_lose(t_game *game)
{
	if (game->p_x == game->n_x && game->p_y == game->n_y)
	{
		ft_printf("\nYOU LOSE!\n");
		close_win(game);
	}
}

void	instant_lose(t_game *game)
{
	(void) game;
	ft_printf("\nYOU LOSE!\n");
	close_win(game);
}
