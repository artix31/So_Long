/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:02 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 02:22:58 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		main(int argc, char **argv)
{
	t_maps		maps;
	t_player	player;

	init_maps(&maps);
	init_player(&player);
	if (argc != 2)
		return (write(2, "Wrong Input\n", 13));
	if (chk_format(argv[1]) == 0)
		return (write(2, "Wrong Map format\n", 18));
	if (fill_map(argv[1], &player, &maps) == 0)
		return (write(2, "Wrong Map Size\n", 16));
return (1);
}
