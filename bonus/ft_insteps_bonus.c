/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insteps_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:28:03 by cthresh           #+#    #+#             */
/*   Updated: 2022/02/03 21:28:04 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_clear_steps(t_game *game)
{
	int	k;

	k = 0;
	while (game->map.map_arr[k] != '\0')
	{
		if (game->map.map_arr[k] == 'S')
		{
			game->param.img = mlx_xpm_file_to_image(game->param.mlx,
					game->images.steps, &(game)->param.img_width,
					&(game)->param.img_height);
			if (k == 0)
				game->param.addr = mlx_put_image_to_window(game->param.mlx,
						game->param.mlx_win, game->param.img, 0, 0);
			else
				game->param.addr = mlx_put_image_to_window(game->param.mlx,
						game->param.mlx_win, game->param.img,
						game->param.img_width * (k % (game->map.map_len + 1)),
						game->param.img_height * (k / (game->map.map_len + 1)));
		}
		k++;
	}
}

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
	while (len > 0)
	{
		steps[7 + len] = k % 10 + '0';
		k = k / 10;
		len--;
	}
	return (&steps[0]);
}

void	ft_insteps(t_game *game)
{
	int		i;
	int		k;
	char	*new_arr;

	k = (game->map.map_len + 1) * (game->map.map_width + 1);
	i = 0;
	new_arr = (char *)malloc(k);
	if (!new_arr)
		error_exit("Memory error!\n", game->map.map_arr);
	new_arr[k - 1] = '\0';
	while (game->map.map_arr[i] != '\0')
	{
		new_arr[i] = game->map.map_arr[i];
		i++;
	}
	new_arr[i] = '\n';
	i++;
	while (i < k - 1)
		new_arr[i++] = 'S';
	free(game->map.map_arr);
	game->map.map_arr = NULL;
	game->map.map_arr = new_arr;
}
