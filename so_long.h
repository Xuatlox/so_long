/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:18:47 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/10 18:57:32 by ansimonn         ###   ########.fr       */
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
} mlx_t;

void	display_map(char *map);
void	check_rect(char **tileset);
void	check_walls(char **tileset);
void	error(const char *message, char *map);
int		get_len(const char *map);
void	check_charset(char *map);
int		ft_strlen(char *str);

#endif
