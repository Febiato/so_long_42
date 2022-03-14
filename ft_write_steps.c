/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_steps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:01:37 by cthresh           #+#    #+#             */
/*   Updated: 2022/02/03 21:01:43 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_int_len(int k)
{
	int	len;

	len = 0;
	while (k > 0)
	{
		k = k / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_long(t_game *game)
{
	static char	steps[25] = "COUNT : \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	int			k;
	int			len;

	k = game->map.steps;
	len = ft_int_len(k);
	steps[8 + len] = '\n';
	while (len > 0)
	{
		steps[7 + len] = k % 10 + '0';
		k = k / 10;
		len--;
	}
	return (&steps[0]);
}
