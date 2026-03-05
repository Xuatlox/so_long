/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:11:35 by ansimonn          #+#    #+#             */
/*   Updated: 2026/03/05 16:32:57 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	if (str[i - 1] != 'r' || str[i - 2] != 'e'
		|| str[i - 3] != 'b' || str[i - 4] != '.')
		error("File extension invalid: not a .ber file", NULL);
}
