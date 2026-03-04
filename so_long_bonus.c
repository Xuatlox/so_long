/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:46:29 by ansimonn          #+#    #+#             */
/*   Updated: 2026/03/04 18:08:26 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	window_hook(const int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
}

static void	key_hook(const int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (key == 41)
		mlx_loop_end(mlx->con);
	if (key == 26)
		move(mlx, -1, Y);
	if (key == 4)
		move(mlx, -1, X);
	if (key == 22)
		move(mlx, 1, Y);
	if (key == 7)
		move(mlx, 1, X);
}

static void	init(t_mlx *mlx, char **av)
{
	int	height;

	mlx->tileset = check_map(&mlx->col_left, av[1]);
	mlx->col_max = mlx->col_left;
	mlx->info.title = "So Long";
	mlx->info.width = TILESIZE * ft_strlen(mlx->tileset[0]);
	height = 0;
	while (mlx->tileset[height])
		++height;
	mlx->info.height = height * TILESIZE;
	mlx->win = mlx_new_window(mlx->con, &mlx->info);
	find_start(mlx->tileset, mlx->play_pos);
	mlx->player = mlx_new_image_from_file(mlx->con, "stage_1.png", 0, 0);
	mlx->wall = mlx_new_image_from_file(mlx->con, "wall.png", 0, 0);
	mlx->col = mlx_new_image_from_file(mlx->con, "col.png", 0, 0);
	mlx->exit = mlx_new_image_from_file(mlx->con, "exit.png", 0, 0);
	mlx->floor = mlx_new_image_from_file(mlx->con, "floor.png", 0, 0);
	mlx->enemy = mlx_new_image_from_file(mlx->con, "enemy.png", 0, 0);
	if (!mlx->enemy || !mlx->floor || !mlx->exit || !mlx->col || !mlx->wall
		|| !mlx->player || !mlx->win)
		free_destroy_all(mlx);
	mlx->bg.rgba = 0x00000000;
	mlx->text.rgba = 0x00d9901a;
	mlx->moves = 0;
}

static void	update(void *param)
{
	t_mlx	mlx;

	mlx = *(t_mlx *) param;
	mlx_clear_window(mlx.con, mlx.win, mlx.bg);
	draw_bg(mlx);
	draw_tilemap(mlx);
}

int	main(const int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (0);
	mlx.con = mlx_init();
	if (!mlx.con)
		free_destroy_all(&mlx);
	mlx.info = (mlx_window_create_info){0};
	mlx.play_pos[0] = 0;
	mlx.play_pos[1] = 0;
	init(&mlx, av);
	mlx_on_event(mlx.con, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.con, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.con);
	mlx_add_loop_hook(mlx.con, update, &mlx);
	mlx_loop(mlx.con);
	free_destroy_all(&mlx);
}
