/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:02 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 08:17:05 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		main(int argc, char **argv)
{
	t_maps		maps;
	t_player	player;
	int			fd;

	fd = 0;
	init_maps(&maps);
	init_player(&player);
	if (argc != 2)
		return (write(2, "Wrong Input\n", 13));
	if (!chk_format(argv[1]))
		return (write(2, "Wrong Map format\n", 18));
	if (!map_chk_create(fd, argv[1], &player, &maps))
		return (write(2, "Wrong Map Size\n", 16));
return (1);
}
