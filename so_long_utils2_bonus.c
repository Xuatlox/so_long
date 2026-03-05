/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:35:15 by ansimonn          #+#    #+#             */
/*   Updated: 2026/03/05 13:29:09 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_sprite(t_mlx *mlx)
{
	if (mlx->col_left == 0)
	{
		mlx_destroy_image(mlx->con, mlx->player);
		mlx->player = mlx_new_image_from_file(mlx->con, "stage_3.png", 0, 0);
	}
	else if (mlx->col_left <= mlx->col_max / 2)
	{
		mlx_destroy_image(mlx->con, mlx->player);
		mlx->player = mlx_new_image_from_file(mlx->con, "stage_2.png", 0, 0);
	}
}

static void	enemy_attract(t_mlx *mlx, const int i, const int j)
{
	struct timeval	tv;
	char			*step;

	gettimeofday(&tv, NULL);
	step = NULL;
	if (tv.tv_usec % 2 == 0 && mlx->play_pos[1] < i)
		step = &mlx->tileset[i - 1][j];
	else if (tv.tv_usec % 2 == 0 && mlx->play_pos[1] > i)
		step = &mlx->tileset[i + 1][j];
	else if (tv.tv_usec % 2 == 1 && mlx->play_pos[0] < j)
		step = &mlx->tileset[i][j - 1];
	else if (tv.tv_usec % 2 == 1 && mlx->play_pos[0] > j)
		step = &mlx->tileset[i][j + 1];
	if (!step)
		return ;
	if (*step == 'P')
	{
		*step = 'S';
		free_destroy_all(mlx, 0);
	}
	if (*step != '0')
		return ;
	*step = 'S';
	mlx->tileset[i][j] = '0';
}

static void	enemy_flee(t_mlx *mlx, const int i, const int j)
{
	struct timeval	tv;
	char			*step;

	gettimeofday(&tv, NULL);
	step = NULL;
	if (tv.tv_usec % 2 == 0 && mlx->play_pos[1] < i)
		step = &mlx->tileset[i + 1][j];
	else if (tv.tv_usec % 2 == 0 && mlx->play_pos[1] > i)
		step = &mlx->tileset[i - 1][j];
	else if (tv.tv_usec % 2 == 1 && mlx->play_pos[0] < j)
		step = &mlx->tileset[i][j + 1];
	else if (tv.tv_usec % 2 == 1 && mlx->play_pos[0] > j)
		step = &mlx->tileset[i][j - 1];
	if (!step)
		return ;
	if (*step != '0')
		return ;
	*step = 'S';
	mlx->tileset[i][j] = '0';
}

static void	validate_steps(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->tileset[i])
	{
		j = 0;
		while (mlx->tileset[i][j])
		{
			if (mlx->tileset[i][j] == 'S')
			{
				mlx->tileset[i][j] = 'X';
			}
			++j;
		}
		++i;
	}
}

void	move_enemies(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->tileset[i])
	{
		j = 0;
		while (mlx->tileset[i][j])
		{
			if (mlx->tileset[i][j] == 'X')
			{
				if (mlx->col_left)
					enemy_attract(mlx, i, j);
				else
					enemy_flee(mlx, i, j);
			}
			++j;
		}
		++i;
	}
	validate_steps(mlx);
}
