/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:26:30 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 10:23:02 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chk_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'E')
			{
				game->player.exit_cnt_x = i;
				game->player.exit_cnt_y = j;
			}
			j++;
		}
		i++;
	}
	game->map.atemp[game->player.exit_cnt_x][game->player.exit_cnt_y] = '1';
}

int	map_border_chk2(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.rows && game->map.map[y][0])
	{
		if (game->map.map[y][0] != '1')
			ft_freeall(game->map.atemp, game, 0, 3);
		y++;
	}
	y = 0;
	while (y < game->map.rows && game->map.map[y][game->map.cols - 1])
	{
		if (game->map.map[y][game->map.cols - 1] != '1')
			ft_freeall(game->map.atemp, game, 0, 3);
		y++;
	}
	return (1);
}

int	map_border_chk1(t_game *game)
{
	int		x;

	x = 0;
	while (x < game->map.cols && game->map.map[0][x])
	{
		if (game->map.map[0][x] != '1')
			ft_freeall(game->map.atemp, game, 0, 3);
		x++;
	}
	x = 0;
	while (x < game->map.cols && game->map.map[game->map.rows - 1][x])
	{
		if (game->map.map[game->map.rows - 1][x] != '1')
			ft_freeall(game->map.atemp, game, 0, 3);
		x++;
	}
	return (map_border_chk2(game));
}

int	floodfill(char **map, int x, int y, t_game *game)
{
	if (x >= game->map.rows || y >= game->map.cols || x < 0 || y < 0
		|| map[x][y] == 'F' || map[x][y] == '1')
		return (1);
	if (map[x][y] == 'E')
		game->map.exits++;
	if (map[x][y] == 'C')
		game->map.collectibles++;
	map[x][y] = 'F';
	floodfill(map, x - 1, y, game);
	floodfill(map, x, y + 1, game);
	floodfill(map, x + 1, y, game);
	floodfill(map, x, y - 1, game);
	return (1);
}

void	chk_floodfill(t_game *game)
{
	if (game->map.exits != 1)
		ft_freeall(game->map.atemp, game, 0, 4);
	if (game->map.collectibles < 1)
		ft_freeall(game->map.atemp, game, 0, 4);
	if (game->player.count != 1)
		ft_freeall(game->map.atemp, game, 0, 4);
}
