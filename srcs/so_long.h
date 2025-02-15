/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:18 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/16 02:24:23 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../libft/get_next_line.h"

typedef struct s_maps
{
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
}			t_player;

int		chk_format(char *map_name);
int		fill_map(char *line, t_player *player, t_maps *maps);
int		floodfill(char **map, int x, int y, t_maps *maps);
int		close_reopen(int fd, char *map);
int		ft_identifiers(char c);
int		ft_count_rows(char **map);

int		ft_freeall(char **arr, char** rarr, char *str, int i);
int		map_border_chk1(char **map, int row, int cols);

//initalizations//
void	init_player(t_player *player);
void	init_maps(t_maps *maps);

#endif
