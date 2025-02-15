/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_reopen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:26:20 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/15 01:29:59 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		close_reopen(int fd, char *map)
{
	close (fd);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}
