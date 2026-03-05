/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:18:47 by ansimonn          #+#    #+#             */
/*   Updated: 2026/03/05 16:23:17 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "stdio.h"
# include "MacroLibX/includes/mlx.h"

typedef struct s_mlx
{
	mlx_context				con;
	mlx_window				win;
	char					**tileset;
	mlx_image				player;
	mlx_image				floor;
	mlx_image				wall;
	mlx_image				col;
	mlx_image				exit;
	mlx_color				bg;
	int						play_pos[2];
	int						moves;
	int						col_left;
	mlx_window_create_info	info;
}	t_mlx;

# define TILESIZE 32
# define X 0
# define Y 1

char	**check_map(int *col_left, const char *map);
void	check_rect(char **tileset, int len);
void	check_walls(char **tileset, int len);
void	error(char *message, char **map);
int		get_len(const char *map);
void	check_charset(char **map);
int		ft_strlen(char *str);
void	desalloc(char **ar);
void	*ft_calloc(size_t nmemb, size_t size);
int		check_path(char **tileset, int pos_x, int pos_y);
char	**ft_ardup(char **ar);
char	*get_next_line(int fd);
void	free_destroy_all(t_mlx *mlx);
void	find_start(char **map, int pos[2]);
void	move(t_mlx *mlx, int dir, int coord);
void	draw_tilemap(t_mlx mlx);
void	draw_score(t_mlx mlx);
char	*ft_itoa(int n);
char	*ft_strdup(char *s);
void	draw_bg(t_mlx mlx);
void	check_ber(const char *str);

#endif
