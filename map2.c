/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:19:03 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/12 16:40:24 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(const char *message, char **map)
{
	write(STDERR_FILENO, "Error\n", 6);
	perror(message);
	if (map)
		desalloc(map);
	exit(EXIT_FAILURE);
}

void	check_rect(char **tileset, const int len)
{
	int	i;
	int	j;

	j = 1;
	while (tileset[j])
	{
		i = 0;
		while (tileset[j][i])
			++i;
		if (i != len)
			error("Map is not a rectangle", tileset);
		++j;
	}
}

void	check_walls(char **tileset, int len)
{
	int	i;

	i = -1;
	while (tileset[0][++i])
	{
		if (tileset[0][i] != '1')
			error("Map is not surrounded by walls", tileset);
	}
	i = 0;
	while (tileset[++i])
	{
		if (tileset[i][0] != '1' || tileset[i][len - 1] != '1')
			error("Map is not surrounded by walls", tileset);
	}
	len = -1;
	while (tileset[i - 1][++len])
	{
		if (tileset[i - 1][len] != '1')
			error("Map is not surrounded by walls", tileset);
	}
}

void	check_charset(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C')
			{
				error("Invalid character in map", map);
			}
			++j;
		}
		++i;
	}
}

int	check_path(char **tileset, const int pos_x, const int pos_y)
{
	int	ret;

	ret = 0;
	if (tileset[pos_y][pos_x] == '1')
		return (0);
	if (tileset[pos_y][pos_x] == 'C' || tileset[pos_y][pos_x] == 'E')
		ret = 1;
	tileset[pos_y][pos_x] = '1';
	return (check_path(tileset, pos_x + 1, pos_y) +
		check_path(tileset, pos_x - 1, pos_y) +
		check_path(tileset, pos_x, pos_y + 1) +
		check_path(tileset, pos_x, pos_y - 1) + ret);
}
