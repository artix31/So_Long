/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 06:26:13 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/15 11:01:39 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_freeall(char **arr, char **rarr, char *str, int i)
{
	if (arr)
		free(arr);
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
