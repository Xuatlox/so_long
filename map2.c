/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:19:03 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/11 16:53:25 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(const char *message, char **map)
{
	perror(message);
	if (map)
	{
		while (*map)
		{
			free(*map);
			++map;
		}
		free(map);
	}
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

int	check_path(char **tileset, int pos[2], int obj)
{
	if (tileset[pos[0]][pos[1]] == '1')
		return (0);
	if (tileset[pos[0]][pos[1]] == 'C')
		--obj;
	if (tileset[pos[0]][pos[1]] == 'E' && !obj)
		return (1);
	if (check_path(tileset, pos[0], pos[1] + 1, obj) ||
		check_path(tileset, pos[0], pos[1] - 1, obj) ||
		check_path(tileset, pos[0] + 1, pos[1], obj) ||
		check_path(tileset, pos[0] - 1, pos[1], obj))
		return (1);
	return (0);
}
