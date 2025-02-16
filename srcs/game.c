/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:46:08 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/17 02:18:44 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		win_exit(t_game *game)
{
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.mlx)
	{
		mlx_destroy_display(game->mlx.mlx);
		free(game->mlx.mlx);
		ft_farray(game->map.map);
	}
	exit(0);
	return (0);
}
int		key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape )
		win_exit(game);
	return (0);
}
void	game_start(t_game *game)
{
	game->mlx.mlx = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlx, 64 * game->map.cols, 64 * game->map.rows, "test");
	mlx_hook(game->mlx.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx.win, 17, 0L, win_exit, game);
	mlx_loop(game->mlx.mlx);

}
