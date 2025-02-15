/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format_chk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:28:02 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/15 00:57:37 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		chk_format(char *map_name)
{
	if (ft_strrchr(map_name, '.'))
	{
				if (ft_strncmp(ft_strrchr(map_name, '.'), ".ber\n", 4) == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
