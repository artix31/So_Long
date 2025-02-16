/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:16:14 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 08:16:21 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		final_chk(char **map, t_maps *maps)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < maps->rows)
	{
		while (y < maps->cols)
		{
			if ((map[x][y] != '1') && (map[x][y] != 'F'))
			{
				if (map[x][y] != '0')
				{
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
char	*fill_tmp(int fd, t_maps *maps)
{
	char	*line;
	char	*temp;

	temp = NULL;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		maps->cols = col_size(line);
		maps->rows += 1;
		if (!(maps->cols))
			ft_freeall(fd, NULL, temp, 0);
		temp = ft_strjoin_gnl(temp, line);
		free(line);
		line = get_next_line(fd);
	}
	return (temp);
}

int	map_chk_create(int	fd, char *line, t_player *player, t_maps *maps)
{
	char	*temp;
	char	**atemp;

	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (0);
	temp = fill_tmp(fd, maps);
	if (!temp)
		return (ft_freeall(fd, NULL, NULL, 0));
	maps->map = ft_split(temp, '\n');
	if (!maps->map)
		return (ft_freeall(fd, NULL, temp, 0));
	atemp = ft_cpyarr(maps->map);
		if (!atemp)
			return(ft_freeall(fd, maps->map, NULL, 0));
	free(temp);
	if (!find_player(maps->map, player))
		return (ft_freeall(fd, maps->map, NULL, 0));
	if (!map_border_chk1(maps->map, maps->cols, maps->rows))
		return (ft_freeall(fd, maps->map, NULL, 0));
	if (!floodfill(maps->map, player->x_p, player->y_p, maps))
		return (ft_freeall(fd, maps->map, NULL, 0));
	if (!final_chk(maps->map, maps))
		return (ft_freeall(fd, maps->map, NULL, 0));
	return (ft_freeall(fd, maps->map, NULL, 1));
}
