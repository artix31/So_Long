/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:28:02 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 19:23:54 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_identifiers(char c)
{
	if ((c == '1') || (c == '0') || (c == 'P') || (c == 'E') || (c == 'C'))
		return (1);
	else
		return (0);
}

int	chk_format(int argc, char *map_name)
{
	if (argc != 2)
	{
		write(2, "Wrong Format!\ncorrect Format: So_long Map\n", 43);
		exit (1);
	}
	if (ft_strrchr(map_name, '.'))
	{
		if (ft_strncmp(ft_strrchr(map_name, '.'), ".ber\n", 4) == 0)
			return (1);
		else
		{
			write(2, "Wrong Extension\n", 17);
			exit (1);
		}
	}
	else
	{
		ft_putstr_fd("No Extension Found\n", 2);
		exit (1);
	}
}
