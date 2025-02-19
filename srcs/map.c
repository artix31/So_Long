/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:52:20 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 09:58:05 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_img(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '0')
				floor_img(game, i, j);
			if (game->map.map[i][j] == '1')
				wall_img(game, i, j);
			if (game->map.map[i][j] == 'C')
				collect_img(game, i, j);
			if (game->map.map[i][j] == 'E')
				exit_img(game, i, j);
			if (game->map.map[i][j] == 'P')
				player_img(game);
			j++;
		}
		i++;
	}
	return (1);
}
