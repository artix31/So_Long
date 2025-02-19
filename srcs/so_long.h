/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:18 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/19 10:09:01 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	char	**atemp;
	int		rows;
	int		cols;
	int		exits;
	int		players;
	int		collectibles;
}			t_maps;

typedef struct s_player
{
	void	*img;
	int		x_p;
	int		y_p;
	int		count;
	int		movements;
	int		exit_cnt_x;
	int		exit_cnt_y;
}			t_player;

typedef struct s_img
{
	void	*walls;
	void	*floors;
	void	*collect;
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

int		chk_format(int argc, char *map_name);
int		map_chk_create(int fd, char *line, t_game *game);
int		floodfill(char **map, int x, int y, t_game *game);
int		ft_identifiers(char c);

int		ft_freeall(char **rarr, t_game *game, char *str, int i);
int		ft_freeall_fd(int fd, char *str1, char *str2, int i);
int		map_border_chk1(t_game *game);
int		game_start(t_game *game);
int		map_img(t_game *game);

//initalizations//
void	chk_floodfill(t_game *game);
void	chk_exit(t_game *game);
void	init_game(t_game *game);
void	load_mlx(t_game *game);
void	load_images(t_game *game);
void	player_img(t_game *game);
void	floor_img(t_game *game, int i, int j);
void	collect_img(t_game *game, int i, int j);
void	wall_img(t_game *game, int i, int j);
void	exit_img(t_game *game, int i, int j);
void	omni_free(char *errmsg, t_game *game, int i);
void	player_movement(t_game *game, int x, int y);

#endif
