/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:21:45 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 12:42:05 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_all(t_game *game)
{
	if(game->img.collect)
	{
		mlx_destroy_image(game->mlx.mlx, game->img.collect);
		game->img.collect = NULL;
	}
		if(game->img.walls)
	{
		mlx_destroy_image(game->mlx.mlx, game->img.walls);
		game->img.walls = NULL;
	}
		if(game->img.floors)
	{
		mlx_destroy_image(game->mlx.mlx, game->img.floors);
		game->img.floors = NULL;
	}
		if(game->img.exit)
	{
		mlx_destroy_image(game->mlx.mlx, game->img.exit);
		game->img.exit = NULL;
	}
		if(game->img.player)
	{
		mlx_destroy_image(game->mlx.mlx, game->img.player);
		game->img.player = NULL;
	}
}

void init_imgs(t_game *game)
{
	int height;
	int width;

	destroy_all(game);
	game->img.collect = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/wicked/Collect.xpm", &width, &height);
	if (!game->img.collect)
		omni_free("vvvCollect_img_failvvv\n", game, 6);
	game->img.exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/wicked/Exit.xpm", &width, &height);
	if (!game->img.exit)
		omni_free("vvvExit_img_failvvv\n", game, 6);
	game->img.floors = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/wicked/Diamonds_green.xpm", &width, &height);
	if (!game->img.floors)
		omni_free("vvvFloor_img_failvvv\n", game, 6);
	game->img.walls = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/wicked/Spades_green.xpm", &width, &height);
	if (!game->img.walls)
		omni_free("vvvWall_img_failvvv\n", game, 6);
	game->player.img = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/wicked/Wicked.xpm", &width, &height);
	if (!game->player.img)
		omni_free("vvvPlayer_img_set_errorvvv\n", game, 6);
}

void	load_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		ft_freeall(NULL, game, NULL, 6);
	game->mlx.win = mlx_new_window(game->mlx.mlx, 64 * game->map.cols, 62
			* game->map.rows, "Sphere of the BLACKHOLE!!!!");
	if (!game->mlx.win)
		omni_free("window_mlx_fail\n", game, 6);
}

void	load_images(t_game *game)
{
	init_imgs(game);
	map_img(game);
	player_img(game);
}
