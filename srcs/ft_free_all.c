/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 06:26:13 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 08:02:22 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_freeall(int fd, char **rarr, char *str, int i)
{
	if (fd)
		close(fd);
	if (rarr)
	{
		ft_farray(rarr);
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (i);
}
