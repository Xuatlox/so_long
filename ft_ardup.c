/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ardup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:38:54 by ansimonn          #+#    #+#             */
/*   Updated: 2026/02/23 16:06:44 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	desalloc(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		++i;
	}
	free(ar);
}

static	int	ar_size(char **ar)
{
	int	size;

	if (!ar)
		return (0);
	size = 0;
	while (*ar)
	{
		++size;
		++ar;
	}
	return (size);
}

char	**ft_ardup(char **ar)
{
	char	**new;
	int		i;

	new = ft_calloc(ar_size(ar) + 1, sizeof(char *));
	if (!new)
		error("Malloc error", ar);
	i = 0;
	while (ar[i])
	{
		new[i] = ft_strdup(ar[i]);
		++i;
	}
	return (new);
}
