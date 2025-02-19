/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 03:50:31 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 10:09:36 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.rows || y >= game->map.cols)
		return ;
	if (game->map.map[x][y] == '1')
		return ;
	if (game->map.map[x][y] == 'E' && game->map.collectibles != 0)
		return ;
	else if (game->map.map[x][y] == 'E' && game->map.collectibles == 0)
		omni_free("Congrats you won the game!!\n", game, 10);
	if (game->map.map[x][y] == 'C')
		game->map.collectibles--;
	floor_img(game, game->player.x_p, game->player.y_p);
	game->player.x_p = x;
	game->player.y_p = y;
	player_img(game);
}
