
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
#include "mlx_linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_game {
	int		map_width;
	int		map_height;
	int		player_count;
	int		collect_count;
	int		exit_count;
	int		img_pxl;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*win;
	char	**map;
	void	*player;
	void	*collect;
	void	*enemy;
	void	*exit;
	void	*zero;
	void	*one;
}				t_game;

char	**read_map(char *argv, t_game *game);
void	render_map(t_game *game);
void	check_map(t_game *game);
void	check_walls(t_game *game);
void	check_items(t_game *game);
void	chek_inner_map(t_game *game);
void	init_struct(t_game *game);
int		map_height(t_game *game);
int		map_width(t_game *game);
char	*error(char *msg);

#endif
