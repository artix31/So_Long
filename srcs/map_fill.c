/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:16:14 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 00:51:49 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_row_size(int fd)
{
	char	*line;
	size_t	size;
	size_t	curr;

	line = get_next_line(fd);
	if (!line)
		return (0);
	size = ft_strlen(line);
	if (line[size - 1] == '\n')
		size--;
	if (size < 3)
		return (ft_freeall(NULL, NULL, line, 0));
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		curr = ft_strlen(line);
		if (line[curr - 1] == '\n')
			curr--;
		if (size != curr)
			return (ft_freeall(NULL, NULL, line, 0));
	}
	return (size);
}

int		row_nb(int fd, char *map)
{
	int		i;
	char		*line;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if (ft_strlen(line) < 3)
			return (ft_freeall(NULL, NULL, NULL, 0));
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close_reopen(fd, map);
	//ft_printf("\n\n%d\n\n", i);
	return (i);
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
			{
				ft_putchar('1');
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	floodchars(int fd, t_player *player, t_maps *maps)
{
	char	*line;
	char	*temp = NULL;
	char	**map;

	(void) player;
	line = get_next_line(fd);
	if (!line)
		return (ft_freeall(NULL, NULL, line, 0));
	while (line)
	{
		temp = ft_strjoin_gnl(temp, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(temp, '\n');
	if (!map)
		ft_freeall(NULL, NULL, temp, 0);
	free(temp);
	if (!find_player(map, player))
		return (0);
	maps->rows = ft_count_rows(map);
	maps->cols = ft_strlen(map[0]);
	if (map_border_chk1(map, maps->rows, maps->cols) == 0)
		return (ft_freeall(NULL, map, line, 0));
	if (floodfill(map, player->x_p, player->y_p, maps) == 0)
		return (ft_freeall(NULL, map, line, 0));
	else
		return (ft_freeall(NULL, map, line, 1));
	return (1);
}

int		fill_map(char *line, t_player *player, t_maps *maps)
{
	int		fd;
	static int		rows;

	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (0);
	rows = row_nb(fd, line);
	if (rows < 3)
	{
		close(fd);
		return (0);
	}
	if (check_row_size(fd) == 0)
	{
		close (fd);
		return (0);
	}
	fd = close_reopen(fd, line);
	if (floodchars(fd, player, maps) == 0)
	{
		close(fd);
		return (0);
	}
	fd = close_reopen(fd, line);
	return (1);
}
