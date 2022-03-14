/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:28:28 by cthresh           #+#    #+#             */
/*   Updated: 2022/02/03 21:28:30 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_kartman_left(int i, t_image *images, t_data *param, t_map *map)
{
	map->map_arr[i] = '0';
		map->map_arr[i - 1] = 'K';
		param->img = mlx_xpm_file_to_image(param->mlx,
			images->snow, &(param)->img_width, &(param)->img_height);
		param->addr = mlx_put_image_to_window(param->mlx,
			param->mlx_win, param->img,
			param->img_width * (i % (map->map_len + 1)),
			param->img_height * (i / (map->map_len + 1)));
	if (i % 2 == 0)
			param->img = mlx_xpm_file_to_image(param->mlx, images->kartman_zlo,
				&(param)->img_width, &(param)->img_height);
	else
			param->img = mlx_xpm_file_to_image(param->mlx, images->kartman,
				&(param)->img_width, &(param)->img_height);
		param->addr = mlx_put_image_to_window(param->mlx, param->mlx_win,
			param->img, param->img_width * ((i - 1) % (map->map_len + 1)),
			param->img_height * ((i - 1) / (map->map_len + 1)));
}

static void	ft_kartman_right(int i, t_image *images, t_data *param, t_map *map)
{
		map->map_arr[i] = '0';
		map->map_arr[i + 1] = 'K';
		param->img = mlx_xpm_file_to_image(param->mlx, images->snow,
			&(param)->img_width, &(param)->img_height);
		param->addr = mlx_put_image_to_window(param->mlx, param->mlx_win,
			param->img, param->img_width * (i % (map->map_len + 1)),
			param->img_height * (i / (map->map_len + 1)));
	if (i % 2 == 0)
			param->img = mlx_xpm_file_to_image(param->mlx, images->kartman_zlo,
				&(param)->img_width, &(param)->img_height);
	else
			param->img = mlx_xpm_file_to_image(param->mlx, images->kartman,
				&(param)->img_width, &(param)->img_height);
		param->addr = mlx_put_image_to_window(param->mlx, param->mlx_win,
			param->img, param->img_width * ((i + 1) % (map->map_len + 1)),
			param->img_height * ((i + 1) / (map->map_len + 1)));
}

void	ft_enemy_move(int i, t_image *images, t_data *param, t_map *map)
{
	if (map->steps % 7 == 0 && i % 3 == 0)
		map->enemy_flag = map->enemy_flag * (-1);
	if ((map->enemy_flag == -1) && map->map_arr[i - 1] != '1'
		&& map->map_arr[i - 1] != 'C' && map->map_arr[i - 1] != 'E')
	{
		if (map->map_arr[i - 1] == 'P')
			error_exit(NULL, map->map_arr);
		ft_kartman_left(i, images, param, map);
	}
	else if (map->enemy_flag == 1 && map->map_arr[i + 1] != '1'
		&& map->map_arr[i + 1] != 'C' && map->map_arr[i + 1] != 'E')
	{
		if (map->map_arr[i + 1] == 'P')
			error_exit(NULL, map->map_arr);
		ft_kartman_right(i, images, param, map);
	}
	else
		map->enemy_flag = map->enemy_flag * (-1);
}

int	ft_enemy(t_game *game)
{
	if (game->map.map_arr[game->map.pos] == '\0')
		game->map.pos = 0;
	while (game->map.map_arr[game->map.pos] != '\0')
	{
		if (game->map.speed % (8000
				/ (game->map.map_len * game->map.map_width)) == 5)
		{
			if (game->map.map_arr[game->map.pos] == 'K')
			{
				ft_enemy_move(game->map.pos,
					&game->images, &game->param, &game->map);
				if (game->map.enemy_flag == 1)
					game->map.pos++;
			}
			game->map.pos++;
			game->map.speed++;
		}
		else
		{
			game->map.speed++;
			break ;
		}
	}
	return (0);
}
