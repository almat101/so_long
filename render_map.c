/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale <ale@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:28:17 by amatta            #+#    #+#             */
/*   Updated: 2023/07/24 00:35:55 by ale              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map_width(game) * 128,
			map_height(game) * 128, "so_long");
	game->player = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm",
			&game->img_pxl, &game->img_pxl);
	game->one = mlx_xpm_file_to_image(game->mlx, "./img/one.xpm",
			&game->img_pxl, &game->img_pxl);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy.xpm",
			&game->img_pxl, &game->img_pxl);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm",
			&game->img_pxl, &game->img_pxl);
	game->zero = mlx_xpm_file_to_image(game->mlx, "./img/zero.xpm",
			&game->img_pxl, &game->img_pxl);
	game->collect = mlx_xpm_file_to_image(game->mlx, "./img/collect.xpm",
			&game->img_pxl, &game->img_pxl);
	draw_map(game);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->one,
					x * 128, y * 128);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->zero,
					x * 128, y * 128);
			draw_map2(game, y, x);
			x++;
		}
		y++;
	}
}

void	draw_map2(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->zero,
			x * 128, y * 128);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			x * 128, y * 128);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect,
			x * 128, y * 128);
}
