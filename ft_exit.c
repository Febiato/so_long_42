/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:07:12 by cthresh           #+#    #+#             */
/*   Updated: 2022/01/28 15:07:13 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_exit(t_game *game)
{
	if (game->map.map_arr != NULL)
	{
		free(game->map.map_arr);
		game->map.map_arr = NULL;
	}
	exit(1);
}

void	ft_putstr(char *s)
{
	int	i;
	int	k;

	k = (int)ft_strlen(s);
	i = 0;
	if (s)
	{
		while (i < k)
		{
			write(2, (unsigned char *)&s[i], 1);
			i++;
		}
	}
}

void	error_exit(char *str, char *memory)
{
	if (memory != NULL)
	{
		free(memory);
		memory = NULL;
	}
	if (str)
		ft_putstr(str);
	exit(1);
}

void	ft_error(t_game *game)
{
	write(2, "Error\n", 6);
	if (game->map.map_len == -1)
		error_exit("Map is not rectangular!", game->map.map_arr);
	if (game->items.coin < 1)
		error_exit("No collectible items!", game->map.map_arr);
	if (game->items.exit < 1)
		error_exit("No exit!", game->map.map_arr);
	if (game->items.player != 1)
		error_exit("Must have one player on the map!", game->map.map_arr);
	if (game->items.fail > 0)
		error_exit("Wrong symbol on the map!", game->map.map_arr);
}
