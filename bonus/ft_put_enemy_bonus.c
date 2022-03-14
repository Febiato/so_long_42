/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:27:34 by cthresh           #+#    #+#             */
/*   Updated: 2022/02/03 21:27:36 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_enemy(t_game *game)
{
	int	kmax;
	int	i;

	i = 0;
	kmax = game->items.empty / 10;
	while (kmax > 0 && game->map.map_arr[i] != '\0')
	{
		if (game->map.map_arr[i] == '0' && game->map.map_arr[i + 1] == '0'
			&& game->map.map_arr[i + 2] == '0'
			&& game->map.map_arr[i + 3] == '0')
		{
			if ((game->map.map_arr[i - game->map.map_len - 2] == '0'
					|| game->map.map_arr[i + game->map.map_len + 1] == '0')
				&& i % 2 == 0)
			{
				game->map.map_arr[i] = 'K';
				kmax--;
			}
		}
		i++;
	}
}
