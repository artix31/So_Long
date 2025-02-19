/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:46:08 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 10:01:47 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_exit(t_game *game)
{
	omni_free("Game Exited Successfully\n", game, 15);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		win_exit(game);
	if (keycode == XK_Up ||  keycode == XK_w)
		player_movement(game, game->player.x_p - 1, game->player.y_p);
	else if (keycode == XK_Down || keycode == XK_s)
		player_movement(game, game->player.x_p + 1, game->player.y_p);
	else if (keycode == XK_Right || keycode == XK_d)
		player_movement(game, game->player.x_p, game->player.y_p + 1);
	else if (keycode == XK_Left || keycode == XK_a)
		player_movement(game, game->player.x_p, game->player.y_p - 1);
	return (0);
}

int	game_start(t_game *game)
{
	load_mlx(game);
	load_images(game);
	mlx_hook(game->mlx.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx.win, 17, 0L, win_exit, game);
	mlx_loop(game->mlx.mlx);
	return (0);
}
