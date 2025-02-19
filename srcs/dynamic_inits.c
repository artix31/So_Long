/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_inits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 01:49:39 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 10:38:45 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_img(t_game *game, int i, int j)
{
	int	collect;

	collect = mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.collect, j * 64, i * 62);
	if (collect < 0)
		omni_free("Collect_window_fail\n", game, 6);
}

void	exit_img(t_game *game, int i, int j)
{
	int	exit;

	exit = mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.exit, j * 64, i * 62);
	if (exit < 0)
		omni_free("Exit_window_fail\n", game, 6);
}

void	floor_img(t_game *game, int i, int j)
{
	int	floor;

	floor = mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.floors, j * 64, i * 62);
	if (floor < 0)
		omni_free("Floor_window_error\n", game, 6);
}

void	wall_img(t_game *game, int i, int j)
{
	int	wall;

	wall = mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.walls, j * 64, i * 62);
	if (wall < 0)
		omni_free("Wall_window_error\n", game, 6);
}

void player_img(t_game *game)
{
	int	player;

	player = mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->player.img, game->player.y_p * 64, game->player.x_p * 62);
	game->player.movements++;
	if (game->player.movements > 0)
		ft_printf("Movements: %d\n", game->player.movements);
	if (player < 0)
		omni_free("Player_window_set_error\n", game, 6);
}
