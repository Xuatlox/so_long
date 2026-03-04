/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:45:40 by ansimonn          #+#    #+#             */
/*   Updated: 2026/03/04 18:19:53 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_realloc(char ***old, const int size)
{
	char	**new;
	int		i;

	if (!old || !*old)
		return ;
	i = 0;
	new = ft_calloc(size + 1, sizeof(char *));
	if (!new)
	{
		desalloc(*old);
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

static void	fill_map(char ***content, const char *map)
{
	char	*ret;
	int		i;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error("Can't open map file", NULL);
	i = 0;
	ret = "1";
	*content = ft_calloc(1, sizeof(char *));
	if (!*content)
		error("Malloc error", NULL);
	while (ret)
	{
		ft_realloc(content, i + 1);
		ret = get_next_line(fd);
		if (!ret)
			break ;
		ret[ft_strlen(ret)] = 0;
		(*content)[i] = ret;
		++i;
	}
}

static int	check_char(char **map, const char c)
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
				pos[0] = j;
				pos[1] = i;
				return ;
			}
			++j;
		}
		++i;
	}
}

char	**check_map(int *col_left, const char *map)
{
	char	**tmp;
	char	**tileset;
	int		len;
	int		pos[2];

	fill_map(&tileset, map);
	len = ft_strlen(tileset[0]);
	check_charset(tileset);
	check_char(tileset, 'P');
	check_char(tileset, 'E');
	*col_left = check_char(tileset, 'C');
	check_rect(tileset, len);
	check_walls(tileset, len);
	find_start(tileset, pos);
	tmp = ft_ardup(tileset);
	if (check_path(tmp, pos[0], pos[1]) != *col_left + 1)
	{
		desalloc(tileset);
		error("No correct escape path", tmp);
	}
	desalloc(tmp);
	return (tileset);
}
