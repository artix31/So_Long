/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:28:02 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 08:51:39 by amashhad         ###   ########.fr       */
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
