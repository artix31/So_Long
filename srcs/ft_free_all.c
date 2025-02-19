/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 06:26:13 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 10:06:01 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printerror(int i)
{
	// if (i == 0)
	// 	ft_putstr_fd("success", 2);
	if (i == 1)
		ft_putstr_fd("Fail", 2);
	if (i == 2)
		ft_putstr_fd("Malloc Fail\n", 2);
	if (i == 3)
		ft_putstr_fd("Border Error\n", 2);
	if (i == 4)
		ft_putstr_fd("Floodfill Error\n", 2);
	if (i == 5)
		ft_putstr_fd("Unbeatable game!\n", 2);
	if (i == 6)
		ft_putstr_fd("MLX Error\n", 2);
}

int	ft_freeall(char **rarr, t_game *game, char *str, int i)
{
	if (rarr)
	{
		ft_farray(rarr);
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
	if (game->map.map && i != 0)
		ft_farray(game->map.map);
	printerror(i);
	if (i != 0)
		exit (i);
	return (i);
}

void	omni_free2(t_game *game)
{
	if (game->img.collect)
	{
		mlx_destroy_image(game->mlx.mlx, game->img.collect);
		game->img.collect = NULL;
	}
	if (game->img.exit)
	{
		mlx_destroy_image(game->mlx.mlx, game->img.exit);
		game->img.exit = NULL;
	}
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.mlx)
		mlx_destroy_display(game->mlx.mlx);
}

void	omni_free(char *errmsg, t_game *game, int i)
{
	if (game->player.img)
	{
		mlx_destroy_image(game->mlx.mlx, game->player.img);
		game->player.img = NULL;
	}
	if (game->img.floors)
	{
		mlx_destroy_image(game->mlx.mlx, game->img.floors);
		game->img.floors = NULL;
	}
	if (game->img.walls)
	{
		mlx_destroy_image(game->mlx.mlx, game->img.walls);
		game->img.walls = NULL;
	}
	omni_free2(game);
	ft_putstr(errmsg);
	ft_freeall(NULL, game, game->mlx.mlx, i);
}

int	ft_freeall_fd(int fd, char *str1, char *str2, int i)
{
	if (fd)
		close(fd);
	if (str1)
	{
		free(str1);
		str1 = NULL;
	}
	if (str2)
	{
		free(str2);
		str2 = NULL;
	}
	printerror(i);
	if (i != 0)
		exit (i);
	return (i);
}
