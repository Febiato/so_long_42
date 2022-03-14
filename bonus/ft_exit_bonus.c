/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:28:13 by cthresh           #+#    #+#             */
/*   Updated: 2022/02/03 21:28:15 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	destroy_exit(t_game *game)
{
	if (game->map.map_arr != NULL)
	{
		free(game->map.map_arr);
		game->map.map_arr = NULL;
	}
	exit(1);
}

void	ft_exit_finish(t_image *images, t_data *param, t_map *map)
{
	int	i;

	i = 0;
	images->exit = "img/exit_finish.xpm";
	param->img = mlx_xpm_file_to_image(param->mlx,
			images->exit, &(param)->img_width, &(param)->img_height);
	while (map->map_arr[i] != '\0')
	{
		if (map->map_arr[i] == 'E')
		param->addr = mlx_put_image_to_window(param->mlx, param->mlx_win,
					param->img, param->img_width * (i % (map->map_len + 1)),
					param->img_height * (i / (map->map_len + 1)));
		i++;
	}
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
