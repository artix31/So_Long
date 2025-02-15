/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_everything.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:57:11 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 02:23:51 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_maps(t_maps *maps)
{
	maps->rows = 0;
	maps->cols = 0;
	maps->exits = 0;
	maps->players = 0;
	maps->collectibles = 0;
}
void	init_player(t_player *player)
{
	player->x_p = 0;
	player->y_p = 0;
	player->count = 0;
}
