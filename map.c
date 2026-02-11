/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:45:40 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/11 18:05:20 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_realloc(char **old, const int size)
{
	char	*new;
	int	i;

	if (!old || !*old)
		return ;
	i = 0;
	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
	{
		free(*old);
		exit(EXIT_FAILURE);
	}
	while ((*old)[i] && i < size)
	{
		new[i] = (*old)[i];
		++i;
	}
	free(*old);
	*old = new;
}

static void fill_map(char **content, const char *map)
{
	int		ret;
	int		i;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error("Can't open map file", NULL);
	i = 0;
	ret = 1;
	*content = ft_calloc(1, sizeof(char));
	if (!*content)
		error("Malloc error (Map)", NULL);
	while (ret > 0)
	{
		ft_realloc(content, i + 1);
		ret = read(fd, &(*content)[i], 1);
		if (ret < 0)
			error("Read error", content);
		++i;
	}
}

static int check_char(char **map, const char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				++count;
			++j;
		}
		++i;
	}
	if (c == 'P' && count != 1)
		error("Unexistant or multiple starting player position", map);
	if (c == 'E' && count != 1)
		error("Unexistant or multiple exit on map", map);
	if (c == 'C' && count == 0)
		error("No collectibles on map", map);
	return (count);
}

void	find_start(char **map, int pos[2])
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos[0] = i;
				pos[1] = j;
				return ;
			}
			++j;
		}
		++i;
	}
}

void display_map(char *map)
{
	char	*content;
	char	**tileset;
	int		len;
	int		pos[2];
	int		obj;

	fill_map(&content, map);
	tileset = ft_split(content, '\n');
	free(content);
	len = ft_strlen(tileset[0]);
	check_charset(tileset);
	check_char(tileset, 'P');
	check_char(tileset, 'E');
	obj = check_char(tileset, 'C');
	check_rect(tileset, len);
	check_walls(tileset, len);
	find_start(tileset, pos);
	if (obj != check_path(, pos, obj))
		error("No escape path found", tileset);
}
