/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:45:40 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/10 18:33:33 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "so_long.h"

static void	ft_realloc(char **old, const int size)
{
	char	*new;
	int	i;

	if (!old || !*old)
		return ;
	i = 0;
	new = malloc(size * sizeof(char));
	if (!new)
	{
		free(*old);
		exit(EXIT_FAILURE);
	}
	while (*old[i] && i < size - 1)
	{
		new[i] = *old[i];
		++i;
	}
	new[i] = 0;
	free(*old);
	*old = new;
}

static void fill_map(char **map, const int fd)
{
	int		ret;
	int		i;

	i = 0;
	ret = 1;
	*map = malloc(sizeof(char));
	if (!*map)
		error("Malloc error (Map)", NULL);
	while (ret > 0)
	{
		ft_realloc(map, i + 2);
		ret = read(fd, &map[i], 1);
		if (ret < 0)
			error("Read error", *map);
		++i;
	}
}

static void check_char(char *map, const char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == c)
			++count;
		++i;
	}
	if (((c == 'P' || c == 'E') && count != 1) || (c == 'C' && count < 1))
	{
		if (c == 'P' && count == 0)
			error("No starting player position defined", map);
		if (c == 'E' && count == 0)
			error("No exit on map", map);
		if (c == 'C' && count == 0)
			error("No collectibles on map", map);
		if (c == 'P' && count > 1)
			error("Too many starting player positions defined", map);
		if (c == 'E' && count > 1)
			error("Too many exits on map", map);
	}
}

void display_map(char *map)
{
    int		fd;
	char	*content;
	char	**tileset;

    fd = open(map, O_RDONLY);
    if (fd < 0)
        error("Open error", NULL);
	fill_map(&content, fd);
	check_charset(content);
	check_char(content, 'P');
	check_char(content, 'E');
	check_char(content, 'C');
	tileset =
	check_rect(tileset);
	check_walls(tileset);
}
