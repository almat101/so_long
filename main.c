/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:33:22 by amatta            #+#    #+#             */
/*   Updated: 2023/07/31 13:32:53 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

    srand(time(NULL));
	if (argc != 2)
		error("please load a map!", &game, 0);
	is_dot_ber(argv[1]);
	read_map(argv[1], &game);
	init_struct(&game);
	check_map(&game);
	mlx_init_game(&game);
	render_map_1(&game);
	render_map_2(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop_hook(game.mlx, put_exit_animation, &game);
	mlx_hook(game.win, 17, 0L, close_win, &game);
	mlx_loop(game.mlx);
}
