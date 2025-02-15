/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_floodfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:26:30 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/15 05:44:51 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int		ft_count_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		//ft_printf("%s", map[i]);
		i++;
	}
	return (i);
}
int		floodfill(char ***map, int x, int y)
{
	static int exits;
	static int collects;
	//static int player;
	int		row;
	int		cols;

	row = ft_count_rows(*map);
	cols = ft_strlen(*map[0]);
	ft_printf("rows %d\ncols %d\n", row, cols);
	ft_printf("player.x %d\nplayer.y %d\n", x, y);
	if (x < 0 || y < 0 || x >= row || y >= cols || (*map)[x][y] == '1' || (*map)[x][y] == 'F')
	{
		ft_printf("x: %d y: %d row: %d cols: %d collect %d exits %d (*map)[x][y] %c\n", x, y, row, cols, collects, exits, (*map)[x][y]);
		ft_putstr("here\n");
		return (1);
	}
	if ((*map)[x][y] == 'E')
		exits++;
	if ((*map)[x][y] == 'C')
		collects++;
	ft_printf("%d\n", exits);
	(*map)[x][y] = 'F';
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x + 1, y);
	floodfill(map, x, y - 1);
	if (exits != 1)
		return (0);
	if (collects < 1)
		return (0);
	return (1);
}
