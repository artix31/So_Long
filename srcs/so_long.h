/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:18 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/17 01:20:03 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <mlx.h>
# include <X11/keysym.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_maps
{
	char	**map;
	int		rows;
	int		cols;
	int		exits;
	int		players;
	int		collectibles;
}			t_maps;

typedef struct s_player
{
	int		x_p;
	int		y_p;
	int		count;
}			t_player;

typedef struct s_img
{
	void	*walls;
	void	*floors;
	void	*collects;
	void	*exit;
	void	*player;
}			t_img;

typedef struct s_game
{
	t_player	player;
	t_maps		map;
	t_img		img;
	t_mlx		mlx;
}			t_game;


int		chk_format(char *map_name);
int		map_chk_create(int fd, char *line, t_game *game);
int		floodfill(char **map, int x, int y, t_game *game);
int		ft_identifiers(char c);

int		ft_freeall(int fd, char** rarr, char *str, int i);
int		map_border_chk1(char **map, int row, int cols);

//initalizations//
void	init_player(t_game *game);
void	init_maps(t_game *game);
void	game_start(t_game *game);

#endif
