/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:28:17 by amatta            #+#    #+#             */
/*   Updated: 2023/07/25 16:03:43 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map_width(game) * 64,
			map_height(game) * 64, "so_long");
	game->player_left = mlx_xpm_file_to_image(game->mlx, "./img/player_l.xpm",
			&game->img_pxl, &game->img_pxl);
	game->player_right = mlx_xpm_file_to_image(game->mlx, "./img/player_r.xpm",
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
					x * 64, y * 64);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->zero,
					x * 64, y * 64);
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
			x * 64, y * 64);
	if (game->map[y][x] == 'P')
	{
		if (game->p_direction == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->player_right,
				x * 64, y * 64);
		if (game->p_direction == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->player_left,
				x * 64, y * 64);
	}
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect,
			x * 64, y * 64);
	if (game->map[y][x] == 'N')
		mlx_put_image_to_window(game->mlx, game->win, game->enemy,
			x * 64, y * 64);
	put_exit(game);
	print_move(game);
}

void	put_exit(t_game *game)
{
	if (game->collect_count == game->count_collect)
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			game->e_x * 64, game->e_y * 64);
}
