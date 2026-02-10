/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:16:28 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/10 14:00:25 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
}

static void	key_hook(const int key, void *param)
{
	if (key == 41)
		mlx_loop_end(param);
	/*if (key == 26)
		move up
	if (key == 4)
		move left
	if (key == 22)
		move down
	if (key == 7)
		move right*/
}

int	main(int ac, char **av)
{
	mlx_t	mlx;
	mlx_window_create_info	info;

	if (ac != 2)
		return (0);
	mlx.con = mlx_init();
	info.title = "So Long";
	info.width = 1920;
	info.height = 1080;
	mlx.win = mlx_new_window(mlx.con, &info);
	display_map(av[1]);
	mlx_on_event(mlx.con, mlx.win, MLX_KEYDOWN, key_hook, mlx.con);
	mlx_on_event(mlx.con, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.con);
	mlx_loop(mlx.con);

	mlx_destroy_window(mlx.con, mlx.win);
	mlx_destroy_context(mlx.con);
}
