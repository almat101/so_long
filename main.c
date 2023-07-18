#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include "so_long.h"

#define WIDTH 1920
#define HEIGHT 640

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
}

