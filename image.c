
#include "so_long.h"

void	*image_setup(void *mlx_ptr, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx_ptr, "assets/TheInvokerRight.xpm", width, height));
}
