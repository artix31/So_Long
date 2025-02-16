/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_floodfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:26:30 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 08:09:36 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

int		floodfill(char **map, int x, int y, t_maps *maps)
{
	if (map[x][y] == 'F' || x >= maps->rows ||
		y >= maps->cols || x < 0 || y < 0 || map[x][y] == '1')
			return (1);
	if (map[x][y] == 'E')
		maps->exits++;
	if (map[x][y] == 'C')
		maps->collectibles++;
	map[x][y] = 'F';
	floodfill(map, x - 1, y, maps);
	floodfill(map, x, y + 1, maps);
	floodfill(map, x + 1, y, maps);
	floodfill(map, x, y - 1, maps);
	if (maps->exits != 1)
		return (0);
	if (maps->collectibles < 1)
		return (0);
	return (1);
}
