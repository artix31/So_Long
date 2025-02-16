/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 08:24:53 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 08:42:21 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		arr_size(char **arr)
{
	int		i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i] != NULL)
		i++;
	return (i);
}
char	**ft_cpyarr(char **arr)
{
	int		size;
	int		i;
	char	**temp;

	i = 0;
	size = arr_size(arr);
	if (!size)
		return (NULL);
	temp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!temp)
		return (NULL);
	while (arr[i] != NULL)
	{
		temp[i] = ft_strdup(arr[i]);
		i++;
	}
	temp[size] = NULL;
	return (temp);
}
