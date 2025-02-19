/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_everything.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:57:11 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 12:46:38 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
}

static void	init_imgs(t_img *img)
{
	img->collect = NULL;
	img->exit = NULL;
	img->floors = NULL;
	img->player = NULL;
	img->walls = NULL;
}

static void	init_maps(t_maps *map)
{
	map->map = NULL;
	map->rows = 0;
	map->cols = 0;
	map->exits = 0;
	map->players = 0;
	map->collectibles = 0;
}

static	void	init_player(t_player *player)
{
	player->img = NULL;
	player->x_p = 0;
	player->y_p = 0;
	player->movements = 0;
	player->count = 0;
	player->exit_cnt_x = 0;
	player->exit_cnt_y = 0;
}

void	init_game(t_game *game)
{
	init_mlx(&game->mlx);
	init_player(&game->player);
	init_imgs(&game->img);
	init_maps(&game->map);
}
