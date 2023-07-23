/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale <ale@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:33:22 by amatta            #+#    #+#             */
/*   Updated: 2023/07/24 00:53:42 by ale              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int 	i = 0;

	if (argc != 2)
		error("please load a map!");
	read_map(argv[1],&game);
	init_struct(&game);
	check_map(&game);
	render_map(&game);
	mlx_key_hook(game.win , handle_key, &game);
	mlx_hook(game.win, 17, 0L, close_win, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
}

