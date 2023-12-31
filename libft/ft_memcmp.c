/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:23:25 by amatta            #+#    #+#             */
/*   Updated: 2023/07/25 13:05:47 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (n && *ps1 == *ps2)
	{
		ps1++;
		ps2++;
		n--;
	}
	if (n)
		return (*ps1 - *ps2);
	else
		return (0);
}
