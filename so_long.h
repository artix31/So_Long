/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:47:18 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/28 16:17:03 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include "minilibx/mlx_int.h"
#include "Libft/libft.h"

typedef struct s_image {
    void    *img;
    char    *addr;
    int     bpp;            // Bits per pixel
    int     line_length;    // Length of one line of pixels in bytes
    int     endian;         // Endianness (0 = little, 1 = big)
}   t_image;

void	*image_setup(void *mlx_ptr, int *width, int *height);
int		ft_putwalls(void *screen, void *window);
// int		main(int argc, char **argv);
# endif
