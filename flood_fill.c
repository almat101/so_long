#include "so_long.h"

void flood_fill(t_game *game) {
	
	char ** map;

	map = NULL;
	map = create_dup_map(game);
	flood_fill_recursive(game, map, game->p_y, game->p_x);
    // print_map(map);
	if (check_unreachable_item(game,map)){
        free_map(map);
		error("Flood fill item unreachable!!!", game, 1);
	}
    free_map(map);
}

void flood_fill_recursive(t_game *game, char **map, int y, int x)
{
	if ((y < 0 || y >= game->map_height) || (x < 0 || x >= game->map_width))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill_recursive(game, map, y + 1, x);
	flood_fill_recursive(game, map, y - 1, x);
	flood_fill_recursive(game, map, y, x + 1);
	flood_fill_recursive(game, map, y, x - 1);
}

int check_unreachable_item(t_game *game, char **map) {

	int x;
	int y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{

			if(map[y][x] == 'C' || map[y][x] == 'E')
				return 1;
			x++;
		}
		y++;
	}

	return 0;
}

char **create_dup_map(t_game *game) {

	int i;
	char **new_map;

	i = 0;
	new_map = malloc(sizeof(char *) * (game->map_height + 1));
	while(game->map[i]) {
		new_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	new_map[i] = NULL;
	return new_map;
}