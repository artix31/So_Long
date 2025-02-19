/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:02 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 04:07:59 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;
	int			fd;

	fd = 0;
	chk_format(argc, argv[1]);
	init_game(&game);
	map_chk_create(fd, argv[1], &game);
	game_start(&game);
	ft_farray(game.map.map);
	return (0);
}
