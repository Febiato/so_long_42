/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:06:45 by cthresh           #+#    #+#             */
/*   Updated: 2022/01/28 15:06:46 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_step(int i, char *s, t_data *param, t_map *map)
{
	param->img = mlx_xpm_file_to_image(param->mlx, s,
			&(param)->img_width, &(param)->img_height);
	param->addr = mlx_put_image_to_window(param->mlx, param->mlx_win,
			param->img, param->img_width * (i % (map->map_len + 1)),
			param->img_height * (i / (map->map_len + 1)));
}

void	ft_right(t_image *images, t_data *param, t_map *map, t_items *items)
{
	int	i;

	i = 0;
	while (map->map_arr[i] != 'P')
		i++;
	if (map->map_arr[i + 1] != '1' && map->map_arr[i + 1] != 'E')
	{
		map->steps++;
		if (map->map_arr[i + 1] == 'C')
			items->coin--;
		map->map_arr[i] = '0';
		map->map_arr[i + 1] = 'P';
		ft_put_step(i, images->snow, param, map);
		i++;
		ft_put_step(i, images->kyle_front, param, map);
	}
	else if (map->map_arr[i + 1] == 'E' && items->coin == 0)
	{
		map->steps++;
		error_exit(NULL, map->map_arr);
	}
}

void	ft_left(t_image *images, t_data *param, t_map *map, t_items *items)
{
	int	i;

	i = 0;
	while (map->map_arr[i] != 'P')
		i++;
	if (map->map_arr[i - 1] != '1' && map->map_arr[i - 1] != 'E')
	{
		map->steps++;
		if (map->map_arr[i - 1] == 'C')
			items->coin--;
		map->map_arr[i] = '0';
		map->map_arr[i - 1] = 'P';
		ft_put_step(i, images->snow, param, map);
		i--;
		ft_put_step(i, images->kyle_front, param, map);
	}
	else if (map->map_arr[i - 1] == 'E' && items->coin == 0)
	{
		map->steps++;
		error_exit(NULL, map->map_arr);
	}
}

void	ft_up(t_game *game, t_data *param, t_map *map, int k)
{
	int	i;

	i = 0;
	while (map->map_arr[i] != 'P')
		i++;
	if (map->map_arr[i - k - 1] != '1' && map->map_arr[i - k - 1] != 'E')
	{
		map->steps++;
		if (map->map_arr[i - k - 1] == 'C')
			game->items.coin--;
		map->map_arr[i] = '0';
		map->map_arr[i - k - 1] = 'P';
		ft_put_step(i, game->images.snow, param, map);
		i = i - k - 1;
		ft_put_step(i, game->images.kyle_front, param, map);
	}
	else if (map->map_arr[i - k - 1] == 'E' && game->items.coin == 0)
	{
		map->steps++;
		error_exit(NULL, map->map_arr);
	}
}

void	ft_down(t_game *game, t_data *param, t_map *map, int k)
{
	int	i;

	i = 0;
	while (map->map_arr[i] != 'P')
		i++;
	if (map->map_arr[i + k + 1] != '1' && map->map_arr[i + k + 1] != 'E')
	{
		map->steps++;
		if (map->map_arr[i + k + 1] == 'C')
			game->items.coin--;
		map->map_arr[i] = '0';
		map->map_arr[i + k + 1] = 'P';
		ft_put_step(i, game->images.snow, param, map);
		i = i + k + 1;
		ft_put_step(i, game->images.kyle_front, param, map);
	}
	else if (map->map_arr[i + k + 1] == 'E' && game->items.coin == 0)
	{
		map->steps++;
		error_exit(NULL, map->map_arr);
	}
}
