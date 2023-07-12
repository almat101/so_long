#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include "so_long.h"

#define WIDTH 1920
#define HEIGHT 1024

int	main(int argc, char **argv)
{
	int		fd;
	void	*mlx;
	void	*mlx_win;
	void	*p;
	void	*w;
	void	*bg;
	void	*e;
	int		x = 128;
	char	str[9999];
	int		pl;
	int		wall;
	int		r;
	char 	**ret;
	int 	i = 0;
	if (argc != 2)
	{
		ft_printf("Error\nplease load a map!\n");
		exit(1);
	}

	fd = open(argv[1], 0);
	r = read(fd,str,9999);
	ft_printf("mappa originale:\n%s\n",str);

	ret = ft_split(str,'\n');
	ft_printf("mappa splittata:\n");
	while (ret[i] != NULL)
	{
		ft_printf("riga %d = %s\n",i ,ret[i++]);
	}

	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "map");

	p = mlx_xpm_file_to_image(mlx, "./img/p128.xpm", &x,&x);

	w = mlx_xpm_file_to_image(mlx, "./img/wall128.xpm", &x,&x);

	e = mlx_xpm_file_to_image(mlx, "./img/enemy.xpm", &x,&x);

	bg = mlx_xpm_file_to_image(mlx, "./img/bg128.xpm", &x,&x);

	mlx_put_image_to_window(mlx, mlx_win, w ,0 , 0);
	mlx_put_image_to_window(mlx, mlx_win, w ,128 , 0);
	mlx_put_image_to_window(mlx, mlx_win, w ,256 , 0);

	mlx_put_image_to_window(mlx, mlx_win, w ,0 ,128);
	mlx_put_image_to_window(mlx, mlx_win, bg ,128 , 128);
	mlx_put_image_to_window(mlx, mlx_win, p ,256 ,128);
	mlx_loop(mlx);
}
