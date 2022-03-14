/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:27:25 by cthresh           #+#    #+#             */
/*   Updated: 2022/02/03 21:27:26 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	ft_putmap_extra(
			t_image *images, t_data *param, t_map *map, int k)
{
	if (map->map_arr[k] == '1')
		param->img = mlx_xpm_file_to_image(param->mlx,
				images->wall, &(param)->img_width, &(param)->img_height);
	if (map->map_arr[k] == '0')
		param->img = mlx_xpm_file_to_image(param->mlx,
				images->snow, &(param)->img_width, &(param)->img_height);
	if (map->map_arr[k] == 'C')
		param->img = mlx_xpm_file_to_image(param->mlx,
				images->coin, &(param)->img_width, &(param)->img_height);
	if (map->map_arr[k] == 'P')
		param->img = mlx_xpm_file_to_image(param->mlx,
				images->kyle_front, &(param)->img_width, &(param)->img_height);
	if (map->map_arr[k] == 'E')
		param->img = mlx_xpm_file_to_image(param->mlx,
				images->exit, &(param)->img_width, &(param)->img_height);
	if (map->map_arr[k] == 'K')
		param->img = mlx_xpm_file_to_image(param->mlx,
				images->kartman_zlo, &(param)->img_width, &(param)->img_height);
	if (map->map_arr[k] == 'S')
		param->img = mlx_xpm_file_to_image(param->mlx,
				images->steps, &(param)->img_width, &(param)->img_height);
}

int	key_hooks(int keycode, t_game *game)
{
	if (keycode == 119)
		ft_up(&game->images, &game->param, &game->map, &game->items);
	if (keycode == 97)
		ft_left(&game->images, &game->param, &game->map, &game->items);
	if (keycode == 115)
		ft_down(&game->images, &game->param, &game->map, &game->items);
	if (keycode == 100)
		ft_right(&game->images, &game->param, &game->map, &game->items);
	if (keycode == 65307)
	{
		error_exit(NULL, game->map.map_arr);
	}
	ft_clear_steps(game);
	mlx_string_put(game->param.mlx, game->param.mlx_win, 20,
		64 * game->map.map_width + 20, 255255255, ft_itoa_long(game));
	return (0);
}

void	ft_putmap(t_game *game, t_data *param, t_map *map)
{
	int	k;

	k = 0;
	while (map->map_arr[k] != '\0')
	{
		if (map->map_arr[k] == '\n')
			k++;
		ft_putmap_extra(&(game)->images, &(game)->param, &(game)->map, k);
		if (k == 0)
			param->addr = mlx_put_image_to_window(param->mlx,
					param->mlx_win, param->img, 0, 0);
		else
			param->addr = mlx_put_image_to_window(param->mlx, param->mlx_win,
					param->img, param->img_width * (k % (map->map_len + 1)),
					param->img_height * (k / (map->map_len + 1)));
		k++;
	}
}

void	mlx_window(t_game *game)
{
	game->param.mlx = mlx_init();
	game->param.mlx_win = mlx_new_window(
			game->param.mlx, game->map.map_len * 64,
			(game->map.map_width + 1) * 64, "so_long");
	ft_putmap(game, &(game)->param, &(game)->map);
	mlx_hook(game->param.mlx_win, 2, 1L << 0, key_hooks, game);
	mlx_hook(game->param.mlx_win, 17, 1L << 5, destroy_exit, game);
	mlx_loop_hook(game->param.mlx, ft_enemy, game);
	mlx_loop(game->param.mlx);
}

void	ft_visual(t_game *game)
{
	game->images.kyle_front = "img/kyle_front.xpm";
	game->images.kyle_back = "img/kyle_back.xpm";
	game->images.kyle_left = "img/kyle_left.xpm";
	game->images.kyle_right = "img/kyle_right.xpm";
	game->images.exit = "img/exit.xpm";
	game->images.exit_finish = "img/exit_finish.xpm";
	game->images.wall = "img/wall.xpm";
	game->images.coin = "img/coin.xpm";
	game->images.snow = "img/snow.xpm";
	game->images.kartman_zlo = "img/kartman_zlo.xpm";
	game->images.kartman = "img/kartman.xpm";
	game->images.steps = "img/steps.xpm";
	game->map.enemy_flag = 1;
	game->map.speed = 0;
	game->map.pos = 0;
	game->map.steps = 0;
	mlx_window(game);
}
