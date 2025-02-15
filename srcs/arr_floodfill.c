/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_floodfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:26:30 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 00:33:43 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int		map_border_chk2(char **map, int row, int cols)
{
	int	y;

	y = 1;
	while (y < cols)
	{
		if (map[0][y] != '1')
		{
			ft_putchar('d');
			return (0);
		}
		y++;
	}
	y = 1;
	while (y < cols)
	{
		if (map[row - 1][y] != '1')
		{
			ft_putchar('c');
			return (0);
		}
		y++;
	}
	return (1);
}
int		map_border_chk1(char **map, int row, int cols)
{
	int	x;

	x = 1;
	while (x < row)
	{
		if (map[x][0] != '1')
		{
			ft_putchar('b');
			return (0);
		}
		x++;
	}
	x = 1;
	while (x < row)
	{
		if (map[x][cols - 1] != '1')
		{
			ft_putchar(*map[x]);
			ft_putchar('a');
			return (0);
		}
		x++;
	}
	return(map_border_chk2(map, row, cols));
}
int	ft_count_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}
int		floodfill(char **map, int x, int y, t_maps *maps)
{
	if (map[x][y] == 'F' || x >= maps->rows ||
		y >= maps->cols || x < 0 || y < 0 || map[x][y] == '1')
			return (1);
	if (map[x][y] == 'E')
	{
		maps->exits++;
		ft_putnbr_fd(maps->exits, 1);
	}
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
