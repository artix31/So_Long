#include "so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx_data.mlx = mlx_init();
	if (!game->mlx_data.mlx)
		return (-1);
	game->mlx_data.win = mlx_new_window(game->mlx_data.mlx, game->map.cols * 32,
			game->map.rows * 32, "Ducky Walk");
	if (!game->mlx_data.win)
	{
		mlx_destroy_display(game->mlx_data.mlx);
		free(game->mlx_data.mlx);
		return (-1);
	}
	return (0);
}

void	init_player(t_game *game)
{
	game->player.collected = 0;
	game->player.moves = 0;
}

void	init_images(t_game *game)
{
	game->border.img_ptr = mlx_xpm_file_to_image(game->mlx_data.mlx,
			"./textures/border.xpm", &game->border.img_h, &game->border.img_w);
	game->bckgrnd.img_ptr = mlx_xpm_file_to_image(game->mlx_data.mlx,
			"./textures/grass.xpm", &game->bckgrnd.img_h, &game->bckgrnd.img_w);
	game->wall.img_ptr = mlx_xpm_file_to_image(game->mlx_data.mlx,
			"./textures/wall.xpm", &game->wall.img_h, &game->wall.img_w);
	game->player.image.img_ptr = mlx_xpm_file_to_image(game->mlx_data.mlx,
			"./textures/ducky.xpm", &game->player.image.img_h,
			&game->player.image.img_w);
	game->exit.image.img_ptr = mlx_xpm_file_to_image(game->mlx_data.mlx,
			"./textures/exit.xpm", &game->exit.image.img_h,
			&game->exit.image.img_w);
	game->collect.img_ptr = mlx_xpm_file_to_image(game->mlx_data.mlx,
			"./textures/collect.xpm", &game->collect.img_h,
			&game->collect.img_w);
	if (game->collect.img_ptr == NULL || game->exit.image.img_ptr == NULL
		|| game->player.image.img_ptr == NULL || game->wall.img_ptr == NULL
		|| game->bckgrnd.img_ptr == NULL || game->border.img_ptr == NULL)
		close_window(game, "Missing Assets");
}

void	init_map(t_game *game)
{
	game->map.players = 0;
	game->map.exits = 0;
	game->map.collectibles = 0;
	game->map.rows = 0;
	game->map.cols = 0;
}
