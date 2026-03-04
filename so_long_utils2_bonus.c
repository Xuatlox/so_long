/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:42:00 by ansimonn          #+#    #+#             */
/*   Updated: 2026/03/04 17:20:52 by ansimonn         ###   ########.fr       */
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

	gettimeofday(&tv, NULL);
	if (tv.tv_usec % 2 == 0)
	{
		if (mlx->play_pos[1] < i && mlx->tileset[i - 1][j] == '0')
			mlx->tileset[i - 1][j] = 'S';
		else if (mlx->play_pos[1] > i && mlx->tileset[i + 1][j] == '0')
			mlx->tileset[i + 1][j] = 'S';
		else
			return ;
	}
	else
	{
		if (mlx->play_pos[0] < j && mlx->tileset[i][j - 1] == '0')
			mlx->tileset[i][j - 1] = 'S';
		else if (mlx->play_pos[0] > j && mlx->tileset[i][j + 1] == '0')
			mlx->tileset[i][j + 1] = 'S';
		else
			return ;
	}
	mlx->tileset[i][j] = '0';
}

static void	enemy_flee(t_mlx *mlx, const int i, const int j)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (tv.tv_usec % 2 == 0)
	{
		if (mlx->play_pos[1] < i && mlx->tileset[i + 1][j] == '0')
			mlx->tileset[i + 1][j] = 'S';
		else if (mlx->play_pos[1] > i && mlx->tileset[i - 1][j] == '0')
			mlx->tileset[i - 1][j] = 'S';
		else
			return ;
	}
	else
	{
		if (mlx->play_pos[0] < j && mlx->tileset[i][j + 1] == '0')
			mlx->tileset[i][j + 1] = 'S';
		else if (mlx->play_pos[0] > j && mlx->tileset[i][j - 1] == '0')
			mlx->tileset[i][j - 1] = 'S';
		else
			return ;
	}
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
