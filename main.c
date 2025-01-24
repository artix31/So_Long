/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 05:20:37 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/19 19:39:37 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		close_window(int keycode)
{
	if (keycode == XK_Escape)
		exit (0);
	return (0);
}

int		main()
{
	void	*screen;
	void	*window;
	void	*img;
	int		img_height = 500;
	int		img_width = 500;

	//if (argc != 2 || argv[1] == NULL)
	//return (write(2, "Wrong Number of args\n", 21));
	//if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 5) != 0)
	//return (write(2, "Incorrect Map Format\n", 21));
	//ft_printf("arg no.: %d\nargs: %s\n", argc, argv[1]);
	screen = mlx_init();
	window = mlx_new_window(screen, 1350, 1350, "hello");
	img = image_setup(screen, &img_height, &img_width);
	if (!img)
		return (0);
	mlx_key_hook(window, close_window, NULL);
	mlx_hook(window, 2, 1L<<17, close, &window);
	mlx_put_image_to_window(screen, window, img, 100, 100);
	mlx_loop(screen);
	return (0);
}
