#include "so_long.h"

static void	map_border_check(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.cols)
	{
		if (game->map.map[0][j] != '1' || game->map.map[game->map.rows
			- 1][j++] != '1')
			map_error(game->map, 8);
	}
	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][game->map.cols
			- 1] != '1')
			map_error(game->map, 8);
		i++;
	}
}

static void	map_char_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		if ((int)ft_strlen(game->map.map[i]) != game->map.cols)
			map_error(game->map, 2);
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.map[i][j] == 'P')
				set_player(game, i, j);
			else if (game->map.map[i][j] == 'E')
				set_exit(game, i, j);
			else if (game->map.map[i][j] == 'C')
				game->map.collectibles++;
			else if (game->map.map[i][j] != '0' && game->map.map[i][j] != '1')
				map_error(game->map, 3);
			j++;
		}
		i++;
	}
}

static int	map_dfs_check(t_game *game, t_map map, int i, int j)
{
	static int	exits;
	static int	collects;

	if (map.map[i][j] == 'F' || i == map.rows || j == map.cols || i == 0
		|| j == 0 || map.map[i][j] == '1')
		return (0);
	if (map.map[i][j] == 'E')
		exits += 1;
	if (map.map[i][j] == 'C')
		collects += 1;
	map.map[i][j] = 'F';
	map_dfs_check(game, map, i - 1, j);
	map_dfs_check(game, map, i, j + 1);
	map_dfs_check(game, map, i + 1, j);
	map_dfs_check(game, map, i, j - 1);
	if (exits != 1)
		return (-1);
	if (collects != game->map.collectibles)
		return (-1);
	return (0);
}

static int	map_valid_path_check(t_game *game, t_map tmp_map)
{
	return (map_dfs_check(game, tmp_map, game->player.i, game->player.j));
}

void	map_check(t_game *game)
{
	t_map	tmp_map;
	int		valid_path;

	map_border_check(game);
	map_char_check(game);
	if (game->map.exits != 1)
		map_error(game->map, 4);
	else if (game->map.players != 1)
		map_error(game->map, 5);
	else if (game->map.collectibles < 1)
		map_error(game->map, 6);
	else
	{
		tmp_map = map_copy(game);
		valid_path = map_valid_path_check(game, tmp_map);
			map_free(tmp_map);
		if (valid_path == -1)
			map_error(game->map, 7);
	}
}
