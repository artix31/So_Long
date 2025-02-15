/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:02 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/15 05:39:17 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int		main(int argc, char **argv)
{
	t_player player;

	player.count = 0;
	player.x_p = 0;
	player.y_p = 0;
	if (argc != 2)
		return (write(2, "Wrong Input\n", 13));
	if (chk_format(argv[1]) == 0)
		return (write(2, "Wrong Map format\n", 18));
	if (fill_map(argv[1], &player) == 0)
		return (write(2, "Wrong Map Size\n", 16));
return (0);
}
