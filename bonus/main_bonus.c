/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:27:11 by cthresh           #+#    #+#             */
/*   Updated: 2022/02/03 21:27:13 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	ft_insteps(&game);
	ft_put_enemy(&game);
	ft_visual(&game);
}
