/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:16:28 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/13 17:32:15 by ansimonn         ###   ########.fr       */
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

#include <stdio.h>

static void	update(void *param)
{
	mlx_t	mlx;

	mlx = *(mlx_t *) param;
	display_images(mlx);
}

static void	init(mlx_t **mlx, mlx_window_create_info **info, char **av)
{
	int	s;

	s = TILESIZE;
	*mlx = ft_calloc(1, sizeof(mlx_t));
	*info = ft_calloc(1, sizeof(mlx_window_create_info));
	if (!(*info))
		exit(EXIT_FAILURE);
	(*mlx)->con = mlx_init();
	(*info)->title = "So Long";
	(*info)->width = 1920;
	(*info)->height = 1080;
	(*mlx)->win = mlx_new_window((*mlx)->con, *info);
	(*mlx)->tileset = check_map(av[1]);
	find_start((*mlx)->tileset, (*mlx)->play_pos);
	(*mlx)->player = mlx_new_image_from_file((*mlx)->con, "green.png", &s, &s);
	(*mlx)->wall = mlx_new_image_from_file((*mlx)->con, "white.png", &s, &s);
	(*mlx)->col = mlx_new_image_from_file((*mlx)->con, "yellow.png", &s, &s);
	(*mlx)->exit = mlx_new_image_from_file((*mlx)->con, "blue.png", &s, &s);
	(*mlx)->bg = mlx_new_image_from_file((*mlx)->con, "black.png", &s, &s);
}

int	main(const int ac, char **av)
{
	mlx_t	*mlx;
	mlx_window_create_info	*info;

	if (ac != 2)
		return (0);
	init(&mlx, &info, av);
	mlx_on_event(mlx->con, mlx->win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx->con, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx->con);
	mlx_add_loop_hook(mlx->con, update, mlx);
	mlx_loop(mlx->con);
	free_destroy_all(mlx, info);
}
