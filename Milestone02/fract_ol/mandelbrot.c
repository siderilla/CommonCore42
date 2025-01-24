#include <mlx.h>

void	*mlx;
void	*window;

int	main()
{
	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 800, "Mandelbrot");
	mlx_loop(mlx);
	return (0);
}