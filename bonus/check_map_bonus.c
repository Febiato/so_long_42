/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:28:56 by cthresh           #+#    #+#             */
/*   Updated: 2022/02/03 21:28:57 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_width(char *map, int len)
{
	int	i;

	i = 0;
	i = ft_strlen(map) / len;
	return (i);
}

void	item_check(t_game *game)
{
	int	i;

	i = 0;
	game->items.coin = 0;
	game->items.player = 0;
	game->items.exit = 0;
	game->items.fail = 0;
	game->items.empty = 0;
	while (game->map.map_arr[i] != '\0')
	{
		if (game->map.map_arr[i] == 'C')
			game->items.coin++;
		else if (game->map.map_arr[i] == 'E')
			game->items.exit++;
		else if (game->map.map_arr[i] == 'P')
			game->items.player++;
		else if (game->map.map_arr[i] == '0')
			game->items.empty++;
		else if (game->map.map_arr[i] != '1' && game->map.map_arr[i] != '\n')
			game->items.fail++;
		i++;
	}
	if (game->items.coin < 1 || game->items.exit < 1
		|| game->items.player < 1 || game->items.fail > 0)
		ft_error(game);
}

int	map_len(char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(map) == 0)
		return (-1);
	while (map[j] != '\n' && map[j] != '\0')
		j++;
	if (map[j] == '\0')
		return (-1);
	while (map[i] != '\0')
	{
		while (map[i] != '\n' && map[i] != '\0')
			i++;
		if ((i - j) % (j + 1) != 0 && i != j)
			return (-1);
		if (map[i] == '\0')
			break ;
		i++;
	}
	return (j);
}

int	check_wall(char *map, int len)
{
	int	i;
	int	len_max;

	len_max = ft_strlen(map);
	i = 0;
	while (map[i] != '\0')
	{
		if (i < len && map[i] != '1')
			return (-1);
		if (i >= len_max - len && i != len_max && map[i] != '1')
			return (-1);
		if ((i - len) % (len + 1) == 0 && (map[i - 1] != '1'
				|| map[i - len] != '1'))
			return (-1);
		i++;
	}
	return (0);
}

void	check_map(t_game *game)
{
	game->map.map_len = map_len(game->map.map_arr);
	if (game->map.map_len == -1)
		ft_error(game);
	game->map.map_width = map_width(game->map.map_arr, game->map.map_len);
	item_check(game);
	if (check_wall(game->map.map_arr, game->map.map_len) == -1)
		error_exit("Error\nWrong walls!", game->map.map_arr);
}
