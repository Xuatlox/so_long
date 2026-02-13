/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:18:47 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/13 15:24:00 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "stdio.h"
# include "MacroLibX/includes/mlx.h"

typedef struct mlx_s
{
    mlx_context con;
    mlx_window win;
	char **tileset;
	mlx_image player;
	mlx_image wall;
	mlx_image col;
	mlx_image exit;
	mlx_image bg;
	int	play_pos[2];
} mlx_t;

# define TILESIZE 30
# define X 0
# define Y 1

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
void	display_images(mlx_t mlx);
void	free_destroy_all(mlx_t *mlx, mlx_window_create_info *info);
void	find_start(char **map, int pos[2]);
void	move(mlx_t *mlx, int dir, int coord);

#endif
