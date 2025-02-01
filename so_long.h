/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:47:18 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/31 23:47:02 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	int			exits;
	int			players;
	int			collectibles;
}				t_map;

typedef struct s_image
{
	void		*img_ptr;
	int			img_h;
	int			img_w;
}				t_image;

//
typedef struct s_mlxdata
{
	void		*mlx;
	void		*win;
}				t_mlx_data;

//Player Handling, checks for collectables and No.movements
typedef struct s_player
{
	t_image		image;
	int			i;
	int			j;
	int			collected;
	int			moves;
}				t_player;

//Exit handling, location and such
typedef struct s_exit
{
	t_image		image;
	int			i;
	int			j;
}				t_exit;

//Game Struct, Handles chars
typedef struct s_game
{
	t_mlx_data	mlx_data;
	char		*msg;
	t_map		map;
	t_image		tile;
	t_image		border;
	t_image		wall;
	t_player	player;
	t_image		collect;
	t_exit		exit;
	t_image		bckgrnd;
}				t_game;

//Main Functions
int				init_mlx(t_game *game);
void			init_player(t_game *game);
void			init_images(t_game *game);
void			init_map(t_game *game);
void			destroy_images(t_game *game);
int				close_x(t_game *game);
int				close_window(t_game *game, char *msg);
void			win_game(t_game *game);
void			map_check(t_game *game);
void			map_read(char *file, t_game *game);
void			map_save(char *file, t_game *game);
void			set_player(t_game *game, int i, int j);
void			set_exit(t_game *game, int i, int j);
void			map_error(t_map map, int err);
void			map_free(t_map map);
t_map			map_copy(t_game *game);
int				key_inputs(int keysym, t_game *game);
void			move_vertical(t_game *game, int d);
void			move_horizontal(t_game *game, int d);
void			collect(t_game *game, int new_i, int new_j);
void			free_move(t_game *game, int new_i, int new_j);
void			render_exit(t_game *game);
void			render_map(t_game *game);

#endif
