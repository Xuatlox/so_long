/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:53:32 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/13 17:12:45 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tilemap(const mlx_t mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx.tileset[i / TILESIZE])
	{
		j = 0;
		while (mlx.tileset[i / TILESIZE][j / TILESIZE])
		{
			if (mlx.tileset[i / TILESIZE][j / TILESIZE] == '1')
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.wall, j, i);
			else if (mlx.tileset[i / TILESIZE][j / TILESIZE] == 'P')
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.player, j, i);
			else if (mlx.tileset[i / TILESIZE][j / TILESIZE] == '0')
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.bg, j, i);
			else if (mlx.tileset[i / TILESIZE][j / TILESIZE] == 'E')
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.exit, j, i);
			else if (mlx.tileset[i / TILESIZE][j / TILESIZE] == 'C')
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.col, j, i);
			j += TILESIZE;
		}
		i += TILESIZE;
	}
}

void	display_images(const mlx_t mlx)
{
	draw_tilemap(mlx);
}

void	free_destroy_all(mlx_t *mlx, mlx_window_create_info *info)
{
	desalloc(mlx->tileset);
	mlx_destroy_image(mlx->con, mlx->player);
	mlx_destroy_image(mlx->con, mlx->bg);
	mlx_destroy_image(mlx->con, mlx->exit);
	mlx_destroy_image(mlx->con, mlx->col);
	mlx_destroy_image(mlx->con, mlx->wall);
	mlx_destroy_window(mlx->con, mlx->win);
	mlx_destroy_context(mlx->con);
	free(info);
	free(mlx);
}

void	move(mlx_t *mlx, const int dir, const int coord)
{
	if (coord == X)
	{
		if (mlx->tileset[mlx->play_pos[1]][mlx->play_pos[0] + dir] == '1')
			return ;
		mlx->tileset[mlx->play_pos[1]][mlx->play_pos[0]] = '0';
		mlx->tileset[mlx->play_pos[1]][mlx->play_pos[0] + dir] = 'P';
		mlx->play_pos[0] += dir;
	}
	else
	{
		if (mlx->tileset[mlx->play_pos[1] + dir][mlx->play_pos[0]] == '1')
			return ;
		mlx->tileset[mlx->play_pos[1]][mlx->play_pos[0]] = '0';
		mlx->tileset[mlx->play_pos[1] + dir][mlx->play_pos[0]] = 'P';
		mlx->play_pos[1] += dir;
	}
}
