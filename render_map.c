/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:28:17 by amatta            #+#    #+#             */
/*   Updated: 2023/07/18 17:17:16 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int y;
	int x;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map_width(game) * 128, map_height(game) * 128, "so_long");
	game->player = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img_pxl, &game->img_pxl);
	game->one = mlx_xpm_file_to_image(game->mlx, "./img/one.xpm", &game->img_pxl, &game->img_pxl);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy.xpm", &game->img_pxl, &game->img_pxl);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &game->img_pxl, &game->img_pxl);
	game->zero = mlx_xpm_file_to_image(game->mlx, "./img/zero.xpm", &game->img_pxl, &game->img_pxl);
	game->collect = mlx_xpm_file_to_image(game->mlx, "./img/collect.xpm", &game->img_pxl, &game->img_pxl);

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            char element = game->map[y][x];
            void *img;

            // Determine the image based on the element
            if (element == '1')
                img = game->one;
            else if (element == 'P')
                img = game->player;
            else if (element == 'C')
                img = game->collect;
            else if (element == 'E')
                img = game->exit;
            else if (element == '0')
                img = game->zero;

            // Draw the cell with the corresponding image
            mlx_put_image_to_window(game->mlx, game->win, img, x * 128, y * 128);
            x++;
        }
        y++;
    }
	mlx_loop(game->mlx);
}



