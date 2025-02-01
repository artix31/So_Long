#include "so_long.h"
#include <stdio.h>

void	set_player(t_game *game, int i, int j)
{
	game->map.players++;
	game->player.i = i;
	game->player.j = j;
}

void	set_exit(t_game *game, int i, int j)
{
	game->map.exits++;
	game->exit.i = i;
	game->exit.j = j;
}

void	map_error(t_map map, int err)
{
	if (err == 1)
	{
		printf("Can not open map or malloc error\n");
		exit(-1);
	}
	else if (err == 2)
		printf("Map not rectangular\n");
	else if (err == 3)
		printf("Map contains invalid characters\n");
	else if (err == 4)
		printf("Wrong number of exits in map\n");
	else if (err == 5)
		printf("Wrong number of players in map\n");
	else if (err == 6)
		printf("No collectibles in map\n");
	else if (err == 7)
		printf("Exit and/or some collectibles not reachable \n");
	else if (err == 8)
		printf("Map border error\n");
	else if (err == 9)
		printf("Malloc failure while copying map\n");
	else
		printf("Unknown map error\n");
	map_free(map);
	exit(-1);
}

void	map_free(t_map map)
{
	int	i;

	i = 0;
	if (!map.map[i])
	{
		free(map.map);
		return ;
	}
	while (i < map.rows)
	{
		if (map.map[i])
		{
			free(map.map[i]);
		}
		i++;
	}
	free(map.map);
}

t_map	map_copy(t_game *game)
{
	t_map	tmp_map;
	int		i;

	tmp_map.map = malloc(game->map.rows * sizeof(char *));
	if (!tmp_map.map)
		map_error(game->map, 9);
	i = 0;
	while (i < game->map.rows)
	{
		tmp_map.map[i] = ft_strdup(game->map.map[i]);
		if (!tmp_map.map[i])
			map_error(game->map, 9);
		i++;
	}
	tmp_map.rows = game->map.rows;
	tmp_map.cols = game->map.cols;
	return (tmp_map);
}
