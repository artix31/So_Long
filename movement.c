#include "so_long.h"
#include <stdio.h>

int	key_inputs(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_window(game, "Normal Exit\n");
	else if (keysym == XK_Up)
		move_vertical(game, -1);
	else if (keysym == XK_Down)
		move_vertical(game, 1);
	else if (keysym == XK_Right)
		move_horizontal(game, 1);
	else if (keysym == XK_Left)
		move_horizontal(game, -1);
	return (0);
}

void	move_vertical(t_game *game, int d)
{
	int	new_row;

	new_row = game->player.i + d;
	if (game->map.map[new_row][game->player.j] == '0')
		free_move(game, new_row, game->player.j);
	else if (game->map.map[new_row][game->player.j] == 'C')
		collect(game, new_row, game->player.j);
	else if (game->map.map[new_row][game->player.j] == 'E')
	{
		if (game->player.collected == game->map.collectibles)
			win_game(game);
		else
			free_move(game, new_row, game->player.j);
	}
}

void	move_horizontal(t_game *game, int d)
{
	int	new_col;

	new_col = game->player.j + d;
	if (game->map.map[game->player.i][new_col] == '0')
		free_move(game, game->player.i, new_col);
	else if (game->map.map[game->player.i][new_col] == 'C')
		collect(game, game->player.i, new_col);
	else if (game->map.map[game->player.i][new_col] == 'E')
	{
		if (game->player.collected == game->map.collectibles)
			win_game(game);
		else
			free_move(game, game->player.i, new_col);
	}
}

void	collect(t_game *game, int new_i, int new_j)
{
	free_move(game, new_i, new_j);
	game->player.collected++;
	printf("collectibles = %d\n", game->player.collected);
	if (game->player.collected == game->map.collectibles)
		render_exit(game);
}

void	free_move(t_game *game, int new_i, int new_j)
{
	mlx_put_image_to_window(game->mlx_data.mlx, game->mlx_data.win,
		game->bckgrnd.img_ptr, (32 * game->player.j), (game->player.i * 32));
	game->map.map[game->player.i][game->player.j] = '0';
	game->player.i = new_i;
	game->player.j = new_j;
	game->map.map[game->player.i][game->player.j] = 'P';
	game->player.moves++;
	printf("moves = %d\n", game->player.moves);
	mlx_put_image_to_window(game->mlx_data.mlx, game->mlx_data.win,
		game->player.image.img_ptr, (32 * game->player.j), (game->player.i
			* 32));
}
