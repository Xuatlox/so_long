/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:16:28 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/25 17:28:23 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	window_hook(const int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
}

static void	key_hook(const int key, void *param)
{
	mlx_t *mlx;

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

static void	init(mlx_t **mlx, char **av)
{
	int	height;

	*mlx = ft_calloc(1, sizeof(mlx_t));
	(*mlx)->con = mlx_init();
	if (!(*mlx)->con)
		free_destroy_all(*mlx);
	(*mlx)->tileset = check_map(av[1], *mlx);
	(*mlx)->info.title = "So Long";
	(*mlx)->info.width = TILESIZE * ft_strlen((*mlx)->tileset[0]);
	height = 0;
	while ((*mlx)->tileset[height])
		++height;
	(*mlx)->info.height = height * TILESIZE;
	(*mlx)->win = mlx_new_window((*mlx)->con, &(*mlx)->info);
	find_start((*mlx)->tileset, (*mlx)->play_pos);
	(*mlx)->player = mlx_new_image_from_file((*mlx)->con, "player.png", NULL, NULL);
	(*mlx)->wall = mlx_new_image_from_file((*mlx)->con, "wall.png", NULL, NULL);
	(*mlx)->col = mlx_new_image_from_file((*mlx)->con, "coin.png", NULL, NULL);
	(*mlx)->exit = mlx_new_image_from_file((*mlx)->con, "exit.png", NULL, NULL);
	if (!(*mlx)->exit || !(*mlx)->col || !(*mlx)->wall || !(*mlx)->player || !(*mlx)->win)
		free_destroy_all(*mlx);
	(*mlx)->bg.rgba = 0x00000000;
	(*mlx)->text.rgba = 0x00d9901a;
	(*mlx)->moves = 0;
}

static void	update(void *param)
{
	mlx_t mlx;

	mlx = *(mlx_t *) param;
	mlx_clear_window(mlx.con, mlx.win, mlx.bg);
	draw_tilemap(mlx);
}

int	main(const int ac, char **av)
{
	mlx_t	*mlx;

	if (ac != 2)
		return (0);
	init(&mlx, av);
	mlx_on_event(mlx->con, mlx->win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx->con, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx->con);
	mlx_add_loop_hook(mlx->con, update, mlx);
	mlx_loop(mlx->con);
	free_destroy_all(mlx);
}
