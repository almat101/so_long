
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
#include "mlx_linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_data {
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
