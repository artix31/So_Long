/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:02 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/17 02:06:00 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		main(int argc, char **argv)
{
	t_game		game;
	int			fd;
	int			exit;

	fd = 0;
	if (argc != 2)
		return (write(2, "Wrong Input\n", 13));
	if (!chk_format(argv[1]))
		return (write(2, "Wrong Map format\n", 18));
	init_maps(&game);
	init_player(&game);
	exit = map_chk_create(fd, argv[1], &game);
	if (exit != 1)
	{
		ft_farray(game.map.map);
		write(1, "map_chk_create\n", 16);
		return (exit);
	}
	game_start(&game);
	ft_farray(game.map.map);
return (1);
}
