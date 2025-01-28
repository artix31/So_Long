/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 03:23:54 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/28 05:51:54 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_list
{
	int	x;
	int	y;
	struct s_list *next;
}			t_list;

int	main()
{
	t_list	test;

	test.x = 1;
	test.y = 2;
	int	i = 10;
	while (i > 0)
	{
		test.x++;
		test.y--;
		printf("x:%d\ny:%d\n", test.x, test.y
		test.x = );
		i--;
	}
}
