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

static int	has_two_newlines(char *str)
{
    int		i;
    int		j;
	int		e;

	i = 0;
	j = 1;
	e = 0;
	while(str[i])
		i++;
	e = i - 1;
	while(str[e] == '\n')
		e--;
	i = 0;
	while(str[i] == '\n')
    	i++;
    while(i < e)
    {
		if(str[i] == '\n' && str[j] == '\n')
			return(1);
		i++;
		j++;
	}
	return 0;
}

char	**read_map(char *argv, t_game *game)
{
	int		fd;
	int		r;
	char	*str;

	fd = open(argv, 0);
	str = ft_calloc(sizeof(char), 9999);
	r = read(fd, str, 9999);
	if (r == -1 || r == 0)
		ft_error("read error!", str);
	if(has_two_newlines(str))
		ft_error("newline founded inside the map!", str);
	game->map = ft_split(str, 10);
	close(fd);
	free(str);
	return (game->map);
}