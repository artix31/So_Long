/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:25:18 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/07 01:53:35 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_farray(char	**arr)
{
	int	i;

	i = 0;
	if (arr == NULL && *arr == NULL)
		return ;
	if (arr != NULL && *arr != NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
		return ;
	}
	if (arr != NULL && *arr == NULL)
	{
		free(arr);
		arr = NULL;
		return ;
	}
}
