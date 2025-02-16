/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_everything.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:57:11 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/17 01:48:19 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_maps(t_game *game)
{
	game->map.rows = 0;
	game->map.cols = 0;
	game->map.exits = 0;
	game->map.players = 0;
	game->map.collectibles = 0;
}
void	init_player(t_game *game)
{
	game->player.x_p = 0;
	game->player.y_p = 0;
	game->player.count = 0;
}
