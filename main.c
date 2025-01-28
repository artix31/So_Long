/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 05:20:37 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/28 12:36:54 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int		close_window(int keycode)
{
	if (keycode == XK_Escape)
	{
		exit (1);
	}
	return (0);
}

int		main()
{
	void	*screen;
	void	*window;
	int		imgwidth = 100;
	int		imgheight = 100;
	void	*character;

	screen = mlx_init();
	if (!screen)
		return (write(2, "screenerr\n", 10));
	window = mlx_new_window(screen, 1000, 1000, "test");
	if (!window)
		return (write(2, "windowerr\n", 10));
	if (ft_putwalls(screen, window) == 0)
	{
		character = mlx_xpm_file_to_image(screen, "./assets/TheInvokerLeft.xpm", &imgwidth, &imgheight);
		if (!character)
			return (write(2, "charerr\n", 8));
		mlx_put_image_to_window(screen, window, character, 100, 100);
	}
	mlx_loop(screen);
	return (0);
}
