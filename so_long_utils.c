/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:53:32 by ansimonn          #+#    #+#             */
/*   Updated: 2026/03/05 11:07:16 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tilemap(const t_mlx mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx.tileset[i / TILESIZE])
	{
		j = 0;
		while (mlx.tileset[i / TILESIZE][j / TILESIZE])
		{
			if (mlx.tileset[i / TILESIZE][j / TILESIZE] == 'P')
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.player, j, i);
			if (mlx.tileset[i / TILESIZE][j / TILESIZE] == 'E')
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.exit, j, i);
			if (mlx.tileset[i / TILESIZE][j / TILESIZE] == 'C')
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.col, j, i);
			j += TILESIZE;
		}
		i += TILESIZE;
	}
}

void	draw_bg(const t_mlx mlx)
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
			else
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.floor, j, i);
			j += TILESIZE;
		}
		i += TILESIZE;
	}
}

void	draw_score(const t_mlx mlx)
{
	char	*score;

	score = ft_itoa(mlx.moves);
	if (!score)
		return ;
	write(STDOUT_FILENO, "Score: ", 7);
	write(STDOUT_FILENO, score, ft_strlen(score));
	write(STDOUT_FILENO, "\n", 1);
	free(score);
}

void	free_destroy_all(t_mlx *mlx)
{
	if (mlx->tileset)
		desalloc(mlx->tileset);
	if (mlx->player)
		mlx_destroy_image(mlx->con, mlx->player);
	if (mlx->exit)
		mlx_destroy_image(mlx->con, mlx->exit);
	if (mlx->col)
		mlx_destroy_image(mlx->con, mlx->col);
	if (mlx->wall)
		mlx_destroy_image(mlx->con, mlx->wall);
	if (mlx->floor)
		mlx_destroy_image(mlx->con, mlx->floor);
	if (mlx->win)
		mlx_destroy_window(mlx->con, mlx->win);
	if (mlx->con)
		mlx_destroy_context(mlx->con);
	exit(EXIT_SUCCESS);
}

void	move(t_mlx *mlx, const int dir, const int coord)
{
	char	*step;

	if (coord == X)
		step = &mlx->tileset[mlx->play_pos[1]][mlx->play_pos[0] + dir];
	else
		step = &mlx->tileset[mlx->play_pos[1] + dir][mlx->play_pos[0]];
	if (*step == '1' || (*step == 'E' && mlx->col_left))
		return ;
	if (*step == 'E')
		free_destroy_all(mlx);
	if (*step == 'C')
		--mlx->col_left;
	*step = 'P';
	mlx->tileset[mlx->play_pos[1]][mlx->play_pos[0]] = '0';
	mlx->play_pos[coord] += dir;
	++mlx->moves;
	draw_score(*mlx);
}
