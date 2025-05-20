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

char	*error(char *msg, t_game *game, int flag)
{
	ft_printf("Error, \n");
	ft_printf("%s\n", msg);
	if (flag)
		ft_free_map(game);
	exit(1);
}
