/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:32:04 by amatta            #+#    #+#             */
/*   Updated: 2023/07/18 16:14:39 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *argv,t_game *game)
{
	int		fd;
	int		r;
	char	*str;

	fd = open(argv, 0);
	str = malloc(sizeof (char) * 9999 );
	r = read(fd, str, 9999);
	if (r == -1)
		error("read error!");
	game->map = ft_split(str, 10);
	close(fd);
	free(str);
	return (game->map);
}

void	init_struct(t_game *game)
{
	game->map_width = map_width(game);
	game->map_height = map_height(game);
	game->collect_count = 0;
	game->exit_count = 0;
	game->img_pxl = 128;
}
