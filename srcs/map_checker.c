/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:26:30 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/17 01:45:29 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		map_border_chk2(char **map, int cols, int rows)
{
	int	y;

	y = 0;
	while ( y < rows && map[y][0])
	{
		if (map[y][0] != '1')
			return (0);
		y++;
	}
	y = 0;
	while ( y < rows && map[y][cols - 1])
	{
		if (map[y][cols - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
int		map_border_chk1(char **map, int cols, int rows)
{
	int		x;

	x = 0;
	while(x < cols &&map[0][x])
	{
		if (map[0][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (x < cols && map[rows - 1][x])
	{
		if (map[rows - 1][x] != '1')
			return (0);
		x++;
	}
	return (map_border_chk2(map, cols, rows));
}

int		floodfill(char **map, int x, int y, t_game *game)
{
	if (map[x][y] == 'F' || x >= game->map.rows ||
		y >= game->map.cols || x < 0 || y < 0 || map[x][y] == '1')
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
	if (game->map.exits != 1)
		return (0);
	if (game->map.collectibles < 1)
		return (0);
	return (1);
}
