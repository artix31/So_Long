#include "so_long.h"

void	check_borders(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.cols)
	{
		if (game->map.map[0][j] != '1' || game->map.map[game->map.rows
			- 1][j++] != '1')
			close_window(game, "Map border error\n");
	}
	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][game->map.cols
			- 1] != '1')
			close_window(game, "Map border error\n");
		i++;
	}
}

int	dfs(t_game *game, t_map map, int i, int j)
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
	dfs(game, map, i - 1, j);
	dfs(game, map, i, j + 1);
	dfs(game, map, i + 1, j);
	dfs(game, map, i, j - 1);
	if (exits != 1)
		return (-1);
	if (collects != game->map.collectibles)
		return (-1);
	return (0);
}

int	check_valid_path(t_game *game, t_map tmp_map)
{
	return (dfs(game, tmp_map, game->player.i, game->player.j));
}

t_map	copy_map(t_game *game)
{
	t_map	tmp_map;
	int		i;

	tmp_map.map = malloc(game->map.rows * sizeof(char *));
	if (!tmp_map.map)
		close_window(game, "Malloc failure while copying map\n");
	i = 0;
	while (i < game->map.rows)
	{
		tmp_map.map[i] = ft_strdup(game->map.map[i]);
		i++;
	}
	tmp_map.rows = game->map.rows;
	tmp_map.cols = game->map.cols;
	return (tmp_map);
}

void	check_map(t_game *game)
{
	t_map	tmp_map;
	int		valid_path;

	check_borders(game);
	tmp_map = copy_map(game);
	valid_path = check_valid_path(game, tmp_map);
	map_free(tmp_map);
	if (valid_path == -1)
		close_window(game, "Exit and/or some collectibles not reachable \n");
	else if (game->map.players != 1)
		close_window(game, "wrong number of players in map\n");
	else if (game->map.collectibles < 1)
		close_window(game, "No collectibles in map\n");
}
