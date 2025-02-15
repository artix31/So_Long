/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:18 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/15 05:13:09 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../libft/get_next_line.h"

typedef struct s_map
{
	char	**map;
	int			rows;
	int			cols;
	int			exits;
	int			players;
	int			collectibles;
}			t_map;

typedef struct s_player
{
	void	*img;
	int		x_p;
	int		y_p;
	int		count;
}				t_player;

int		chk_format(char *map_name);
int		fill_map(char *line, t_player *player);
int		floodfill(char ***map, int x, int y);
int		close_reopen(int fd, char *map);
int		ft_identifiers(char c);

#endif
