/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:19:03 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/10 18:00:28 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "so_long.h"

void	error(const char *message, char *map)
{
	perror(message);
	if (map)
		free(map);
	exit(EXIT_FAILURE);
}

void	check_rect(char *map)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = -1;
	while (map[++i] != '\n')
		len++;
	j = 0;
	while (map[++i])
	{
		if (map[i] == '\n')
		{
			if (j != len)
				error("Map is not a rectangle", map);
			j = 0;
		}
		++j;
	}
}

void	check_walls(char *map)
{
	int	i;

	i = -1;
	while (map[++i] != '\n')
	{
		if (map[i] != '1')
			error("Map is not surrounded by walls", map);
	}
	while (map[++i])
	{
		if (map[i] == '\n' && map[i + 1] &&
			(map[i + 1] != '1' || map[i - 1] != '1'))
			error("Map is not surrounded by walls", map);
	}
	while (map[--i] != '\n')
	{
		if (map[i] != '1')
			error("Map is not surrounded by walls", map);
	}
}

void	check_charset(char *map)
{
	while (*map)
	{
		if (*map != '0' && *map != '1' && *map != 'E'
			&& *map != 'P' && *map != 'C')
		{
			error("Invalid character in map", map);
		}
		++map;
	}
}

char	check_path(char *map, int len, int pos, int col)
{
	if (map[pos] == 'E')
		return (1);
	if (!col)
	{
		if (map[pos + 1] == '0' || map[pos + 1] == 'C')
			check_path(map, len, pos + 1, col);
		if (pos - 1 >= 0 && (map[pos - 1] == '0' || map[pos - 1] == 'C'))
			check_path(map, len, pos - 1, col);
		if (map[pos + len] == '0' || map[pos + len] == 'C')
			check_path(map, len, pos + len, col);
		if (pos - len >= 0 && (map[pos - len] == '0' || map[pos - len] == 'C'))
			check_path(map, len, pos - len, col);
	}
	else
	{
		if (map[pos + 1] == '0' || map[pos + 1] == 'E')
			check_path(map, len, pos + 1, col);
		if (pos - 1 >= 0 && (map[pos - 1] == '0' || map[pos - 1] == 'E'))
			check_path(map, len, pos - 1, col);
		if (map[pos + len] == '0' || map[pos + len] == 'E')
			check_path(map, len, pos + len, col);
		if (pos - len >= 0 && (map[pos - len] == '0' || map[pos - len] == 'E'))
			check_path(map, len, pos - len, col);
	}
}
