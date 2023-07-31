/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:08:04 by amatta            #+#    #+#             */
/*   Updated: 2023/07/31 15:58:22 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_img(game);
	mlx_destroy_display(game->mlx);
	ft_free_map(game);
	free(game->mlx);
	exit(0);
}

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player_left);
	mlx_destroy_image(game->mlx, game->player_right);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->enemy);
	mlx_destroy_image(game->mlx, game->exit1);
	mlx_destroy_image(game->mlx, game->exit2);
	mlx_destroy_image(game->mlx, game->exit3);
	mlx_destroy_image(game->mlx, game->zero);
	mlx_destroy_image(game->mlx, game->one);
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
	free(game->map);
}
