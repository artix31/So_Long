/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:16:14 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/17 01:46:23 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		final_chk(char **map, t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < game->map.rows)
	{
		while (y < game->map.cols)
		{
			if ((map[x][y] != '1') && (map[x][y] != 'F'))
			{
				if (map[x][y] != '0')
				{
					ft_putchar(map[x][y]);
					return (0);
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

int		col_size(char *str)
{
	static int	size1;
	int			size2;

	size2 = ft_strlen(str) - 1;
	if (size2 < 3)
		return (0);
	if (size1 == 0)
		size1 = size2;
	if (size1 == size2)
		return (size2);
	return (0);
}
int	find_player(char **map, t_player *player)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if (ft_identifiers(map[i][j]) == 0)
				return(0);
			if (map[i][j] == 'P')
			{
				player->x_p = i;
				player->y_p = j;
				player->count += 1;
			}
			if (player->count > 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
		return (player->count);
}
char	*fill_tmp(int fd, t_game *game)
{
	char	*line;
	char	*temp;

	temp = NULL;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		game->map.cols = col_size(line);
		game->map.rows += 1;
		if (!(game->map.cols))
			ft_freeall(fd, NULL, temp, 0);
		temp = ft_strjoin_gnl(temp, line);
		free(line);
		line = get_next_line(fd);
	}
	return (temp);
}

int	map_chk_create(int	fd, char *line, t_game *game)
{
	char	*temp;
	char	**atemp;

	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (0);
	temp = fill_tmp(fd, game);
	if (!temp)
		return (ft_freeall(fd, NULL, NULL, 8));
	game->map.map = ft_split(temp, '\n');
	if (!game->map.map)
		return (ft_freeall(fd, NULL, temp, 7));
	atemp = ft_cpyarr(game->map.map);
		if (!atemp)
			return(ft_freeall(fd, game->map.map, temp, 6));
	free(temp);
	if (!find_player(game->map.map, &game->player))
		return (ft_freeall(fd, atemp, NULL, 2));
	if (!map_border_chk1(game->map.map, game->map.cols, game->map.rows))
		return (ft_freeall(fd, atemp, NULL, 3));
	if (!floodfill(atemp, game->player.x_p, game->player.y_p, game))
		return (ft_freeall(fd, atemp, NULL, 4));
	if (!final_chk(atemp, game))
		return (ft_freeall(fd, atemp, NULL, 5));
	return (ft_freeall(fd, atemp, NULL, 1));
}
