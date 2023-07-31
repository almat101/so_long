/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:32:04 by amatta            #+#    #+#             */
/*   Updated: 2023/07/31 15:34:54 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *argv, t_game *game)
{
	int		fd;
	int		r;
	char	*str;

	fd = open(argv, 0);
	str = ft_calloc(sizeof(char), 9999);
	r = read(fd, str, 9999);
	if (r == -1)
		error("read error!");
	game->map = ft_split(str, 10);
	close(fd);
	free(str);
	return (game->map);
}
