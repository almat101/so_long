/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:34:11 by amatta            #+#    #+#             */
/*   Updated: 2023/07/25 13:06:39 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_nbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write_str("-2147483648");
			return (11);
		}
		i += write_char('-');
		n = -n;
	}
	if (n > 9)
		i += write_nbr(n / 10);
	i += write_char(n % 10 + 48);
	return (i);
}
