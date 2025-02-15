/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:16:14 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/15 06:21:13 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_row_size(int fd)
{
	char	*line;
	int		size1;
	int		size2;

	size1 = 0;
	size2 = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	size1 = ft_strlen(line);
	while (line && *line != '\0')
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (1);
		size2 = ft_strlen(line);
		if (size1 != size2)
		{
			free(line);
			return (0);
		}
		size1 = size2;
	}
	return (0);
}

int		row_nb(int fd, char *map)
{
	static int		i;
	static int		size;
	char		*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line && *line != '\0')
	{
		size = ft_strlen(line);
		if (size < 3)
		{
			free(line);
			return(0);
		}
		i++;
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			close_reopen(fd, map);
			return (i);
		}
	}
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
	return (1);
}

int	floodchars(int fd, char *file, t_player *player)
{
	char	*line;
	char	**map;
	static int	i;
	//int			j;

	map = malloc(sizeof(map) * row_nb(fd, file));
	if (!map)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	//j = ft_strlen(line);
	while (line && *line != '\0')
	{
		map[i] = ft_strdup(line);
		if (!map[i])
		{
			ft_farray(map);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = '\0';
	if (!find_player(map, player))
		return (0);
	if (floodfill(&map, player->x_p, player->y_p) == 0)
		i = 0;
	ft_farray(map);
	return (i);
}

int		fill_map(char *line, t_player *player)
{
	int		fd;
	int		rows;

	rows = 0;
	//find row nb + check valid row size (size > 2)//
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (0);
	rows = row_nb(fd, line);
	if (rows < 3)
	{
		ft_putstr("row nb\n");
		close(fd);
		return (0);
	}
	//------------------//
	//check row size//
	if (check_row_size(fd) == 0)
	{
		ft_putstr("row size\n");
		close (fd);
		return (0);
	}
	//-----------------//
	//check line validity + floodfill//
	fd = close_reopen(fd, line);
	if (floodchars(fd, line, player) == 0)
	{
		ft_putstr("floodchars\n");
		close(fd);
		return (0);
	}
	fd = close_reopen(fd, line);
	return (1);
}
