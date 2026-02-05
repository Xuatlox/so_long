/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:16:28 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/05 18:42:29 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MacroLibX/includes/mlx.h"

void	key_hook(int key, void *param)
{
	if (key == 41)
		mlx_loop_end(param);
	if (key == )
}

int	main(void)
{
	mlx_t	mlx;
	mlx_window_create_info	info = { 0 };

	mlx.con = mlx_init();
	info.title = "Hello World!";
	info.width = 1020;
	info.height = 800;
	mlx.win = mlx_new_window(mlx.con, &info);
	mlx_on_event(mlx.con, mlx.win, MLX_KEYDOWN, key_hook, mlx.con);
	mlx_loop(mlx.con);
	mlx_set_window_size(mlx.con, mlx.win, 1920, 1080);

	mlx_destroy_window(mlx.con, mlx.win);
	mlx_destroy_context(mlx.con);
}
