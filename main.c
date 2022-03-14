/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:06:23 by cthresh           #+#    #+#             */
/*   Updated: 2022/01/28 15:06:25 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.param.fd = 0;
	game.map.map_arr = NULL;
	if (argc != 2)
		error_exit("Error!\n", NULL);
	check_name(argv[1]);
	game.param.fd = open(argv[1], O_RDONLY);
	read_file(&game);
	ft_visual(&game);
}
