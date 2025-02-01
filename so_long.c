/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 05:20:37 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/31 23:46:41 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	malloc_error(int err)
{
	if (err == 1)
	{
		printf("Can not open map or malloc error\n");
		exit(-1);
	}
	if (err == 2)
	{
		printf("wrong map format\n");
		exit(-1);
	}
}

static void	check_args(int argc, char **argv)
{
	char	*tmp;
	int		fd;

	if (argc != 2)
	{
		printf("Wrong Number of Arguments :(\n");
		exit(-1);
	}
	tmp = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	if (!tmp)
		malloc_error(1);
	if (ft_strncmp(".ber", tmp, 4))
	{
		free(tmp);
		malloc_error(2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Map File not found :(\n");
		free(tmp);
		exit(-1);
	}
	close(fd);
	free(tmp);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	init_map(&game);
	map_read(argv[1], &game);
	map_save(argv[1], &game);
	map_check(&game);
	if (init_mlx(&game) == -1)
	{
		map_free(game.map);
		return (0);
	}
	init_player(&game);
	render_map(&game);
	mlx_hook(game.mlx_data.win, 02, 03, key_inputs, &game);
	mlx_hook(game.mlx_data.win, 17, 0, close_x, &game);
	mlx_loop(game.mlx_data.mlx);
	return (0);
}

