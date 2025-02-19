/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:16:14 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 19:23:14 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	final_chk(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < game->map.rows)
	{
		while (y < game->map.cols)
		{
			if ((game->map.atemp[x][y] != '1') &&
				(game->map.atemp[x][y] != 'F'))
			{
				if (game->map.atemp[x][y] != '0')
					ft_freeall(game->map.atemp, game, 0, 5);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

int	col_size(char *str)
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

int	find_player(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game->map.map[i])
	{
		while (game->map.map[i][j] != '\0')
		{
			if (ft_identifiers(game->map.map[i][j]) == 0)
				ft_freeall(game->map.atemp, game, 0, 5);
			if (game->map.map[i][j] == 'P')
			{
				game->player.x_p = i;
				game->player.y_p = j;
				game->player.count += 1;
			}
			if (game->player.count > 1)
				ft_freeall(game->map.atemp, game, 0, 5);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

char	*fill_tmp(int fd, t_game *game)
{
	char	*line;
	char	*temp;

	temp = NULL;
	line = get_next_line(fd);
	if (!line)
		ft_freeall_fd(fd, NULL, NULL, 2);
	while (line)
	{
		game->map.cols = col_size(line);
		game->map.rows++;
		if ((game->map.cols) == 0)
			ft_freeall_fd(fd, line, temp, 2);
		temp = ft_strjoin_gnl(temp, line);
		if (!temp)
			ft_freeall_fd(fd, line, NULL, 2);
		free(line);
		line = get_next_line(fd);
	}
	return (temp);
}

int	map_chk_create(int fd, char *line, t_game *game)
{
	char	*temp;

	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("wrong file\n", 2);
		exit (0);
	}
	temp = fill_tmp(fd, game);
	close(fd);
	game->map.map = ft_split(temp, '\n');
	if (!game->map.map)
		ft_freeall(NULL, game, temp, 2);
	game->map.atemp = ft_cpyarr(game->map.map);
	if (!game->map.atemp)
		ft_freeall(NULL, game, temp, 2);
	free(temp);
	find_player(game);
	map_border_chk1(game);
	floodfill(game->map.atemp, game->player.x_p, game->player.y_p, game);
	chk_exit(game);
	chk_floodfill(game);
	final_chk(game);
	ft_freeall(game->map.atemp, game, NULL, 0);
	return (0);
}
