/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:16:28 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/12 17:35:43 by ansimonn         ###   ########.fr       */
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
	//if (key == 26)
		//move up
	//if (key == 4)
		//move left
	//if (key == 22)
		//move down
	//if (key == 7)
		//move right
}

static void	update(void *param)
{
	mlx_t	mlx;
	imgs_t	*imgs;
	int		i;

	mlx = *(mlx_t *) param;
	imgs = ft_calloc(1, sizeof(imgs_t));
	imgs->wall = mlx_new_image_from_file(mlx.con, "white.png", NULL, NULL);
	imgs->player = mlx_new_image_from_file(mlx.con, "green.png", NULL, NULL);
	imgs->col = mlx_new_image_from_file(mlx.con, "yellow.png", NULL, NULL);
	imgs->exit = mlx_new_image_from_file(mlx.con, "blue.png", NULL, NULL);
	imgs->bg = mlx_new_image_from_file(mlx.con, "black.png", NULL, NULL);
	i = 0;
	while ()
}

int	main(const int ac, char **av)
{
	mlx_t	mlx;
	mlx_window_create_info	*info;
	static char	**tileset;

	if (ac != 2)
		return (0);
	mlx.con = mlx_init();
	info = ft_calloc(1, sizeof(mlx_window_create_info));
	info->title = "So Long";
	info->width = 1920;
	info->height = 1080;
	mlx.win = mlx_new_window(mlx.con, info);
	tileset = check_map(av[1]);
	mlx_on_event(mlx.con, mlx.win, MLX_KEYDOWN, key_hook, mlx.con);
	mlx_on_event(mlx.con, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.con);
	mlx_add_loop_hook(mlx.con, update, &mlx);
	mlx_loop(mlx.con);

	desalloc(tileset);
	free(info);
	mlx_destroy_window(mlx.con, mlx.win);
	mlx_destroy_context(mlx.con);
}
