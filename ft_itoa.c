/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:59 by ansimonn          #+#    #+#             */
/*   Updated: 2026/03/04 13:17:43 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static unsigned int	get_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static void	fill_res(char *res, int n, const int size)
{
	int		i;
	int		neg;

	i = size - 1;
	res[size] = 0;
	neg = 0;
	if (n < 0)
	{
		res[0] = '-';
		neg = 1;
		n = -n;
	}
	while (i >= neg)
	{
		res[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	size;

	if (n == -2147483648)
	{
		res = ft_strdup("-2147483648");
		return (res);
	}
	size = get_size(n);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	fill_res(res, n, size);
	return (res);
}
