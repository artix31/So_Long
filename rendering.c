#include "so_long.h"

void	render_exit(t_game *game)
{
	game->map.map[game->exit.i][game->exit.j] = 'E';
	mlx_put_image_to_window(game->mlx_data.mlx, game->mlx_data.win,
		game->exit.image.img_ptr, (32 * game->exit.j), (game->exit.i * 32));
}

static void	tile_to_print(t_game *game, int i, int j)
{
	if (i == 0 || i == game->map.rows - 1 || j == 0 || j == game->map.cols - 1)
		game->tile.img_ptr = game->border.img_ptr;
	else if (game->map.map[i][j] == '1')
		game->tile.img_ptr = game->wall.img_ptr;
	else if (game->map.map[i][j] == '0')
		game->tile.img_ptr = game->bckgrnd.img_ptr;
	else if (game->map.map[i][j] == 'P')
		game->tile.img_ptr = game->player.image.img_ptr;
	else if (game->map.map[i][j] == 'E')
	{
		if (game->player.collected == game->map.collectibles)
			game->tile.img_ptr = game->exit.image.img_ptr;
		else
			game->tile.img_ptr = game->bckgrnd.img_ptr;
	}
	else if (game->map.map[i][j] == 'C')
		game->tile.img_ptr = game->collect.img_ptr;
	else
	{
		game->tile.img_ptr = NULL;
		exit(-1);
	}
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	init_images(game);
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			tile_to_print(game, i, j);
			mlx_put_image_to_window(game->mlx_data.mlx, game->mlx_data.win,
				game->tile.img_ptr, (32 * j), (i * 32));
			j++;
		}
		i++;
	}
}
