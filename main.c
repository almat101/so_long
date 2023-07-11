#include "mlx_linux/mlx.h"

int	main()
{
	void	*mlx;
	void	*mlx_win;
	int 	i = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx,1000,1000, "hello world?");
	while (i < 250)
	{
		mlx_pixel_put(mlx,mlx_win,500 + i,500,0xFF0000);
		i++;
	}
	i = 0;
	while (i < 250)
	{
		mlx_pixel_put(mlx,mlx_win,500,250  + i,0xFF0000);
		i++;
	}
	i = 0;
	while (i < 250)
	{
		mlx_pixel_put(mlx,mlx_win,500 + i,250,0xFF0000);
		i++;
	}
	i = 0;
	while (i < 250)
	{
		mlx_pixel_put(mlx,mlx_win,750,250 + i,0xFF0000);
		i++;
	}
	mlx_loop(mlx);
}
