/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:18:47 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/12 17:34:36 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "stdio.h"
# include "MacroLibX/includes/mlx.h"

typedef struct imgs_s
{
	mlx_image player;
	mlx_image wall;
	mlx_image col;
	mlx_image exit;
	mlx_image bg;
} imgs_t;

typedef struct mlx_s
{
    mlx_context con;
    mlx_window win;
} mlx_t;

char	**check_map(char *map);
void	check_rect(char **tileset, int len);
void	check_walls(char **tileset, int len);
void	error(const char *message, char **map);
int		get_len(const char *map);
void	check_charset(char **map);
int		ft_strlen(char *str);
void	desalloc(char **ar);
void	*ft_calloc(size_t nmemb, size_t size);
int		check_path(char **tileset, int pos_x, int pos_y);
char	**ft_ardup(char **ar);
char	*get_next_line(int fd);

#endif
