#include "so_long.h"

int		ft_putwalls(void *screen, void *window)
{
	int		x;
	int		tx;
	int		y;
	int		height;
	int		width;
	void	*wall;


	height  = 15;
	width = 15;
	tx = 0;
	x = 0;
	y = 0;
	wall = mlx_xpm_file_to_image(screen, "./assets/wall_tile.xpm", &height, &width);
	if (!wall)
		ft_putstr_fd("Wall Img Error", 2);
	while (y <= 1000)
	{
		tx+= 0;
		while (x <= 1000)
		{
			mlx_put_image_to_window(screen, window, wall, x, y);
			x+= 10;
		}
		x = 0;
		y+= 10;
	}
	return (0);
}
