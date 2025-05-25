#include "so_long.h"

void	init_struct(t_game *game)
{
	game->map_width = 0;
	game->map_height = 0;
	game->player_count = 0;
	game->collect_count = 0;
	game->exit_count = 0;
	game->enemy_count = 0;
	game->count_collect = 0;
	game->img_pxl = 64;
	game->p_x = 0;
	game->p_y = 0;
	game->e_x = 0;
	game->e_y = 0;
	game->p_moves = 0;
	game->p_direction = 1;
	game->frame = -1;
	game->cords = NULL;
	init_struct2(game);
}

void	init_struct2(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->player_left = NULL;
	game->player_right = NULL;
	game->collect = NULL;
	game->enemy = NULL;
	game->exit1 = NULL;
	game->exit2 = NULL;
	game->exit3 = NULL;
	game->zero = NULL;
	game->one = NULL;
}


//this function init the enemy coordinates it needs the enemy_count so is called in check_map(enemy_count get a value)
void init_enemy_cords(t_game *game)
{
	game->cords = malloc(sizeof(t_enemy_coords) * game->enemy_count);
	if (!game->cords)
    	ft_error("Malloc of enemy cords failed", NULL);
}