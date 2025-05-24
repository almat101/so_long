/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:14:54 by amatta            #+#    #+#             */
/*   Updated: 2023/07/24 12:24:00 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_dot_ber(char *argv)
{
	int		len;

	len = ft_strlen(argv);
	if (ft_strncmp(".ber", argv + len - 4, 4) != 0)
		write(2, "Error,\nMap is not .ber!", 24);
}

void	error(char *msg, t_game *game, int flag)
{
	ft_printf("Error, \n");
	ft_printf("%s\n", msg);
	if (flag)
		ft_free_map(game);
	exit(1);
}

void	ft_error(char *msg, char *str)
{
	ft_printf("Error, \n");
	ft_printf("%s\n", msg);
	free(str);
	exit(1);
}

void	ft_error_mlx(char *msg, t_game *game)
{
	ft_printf("Error, \n");
	ft_printf("%s\n", msg);
	close_win(game);
	exit(1);
}