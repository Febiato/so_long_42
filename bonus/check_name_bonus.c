/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:28:40 by cthresh           #+#    #+#             */
/*   Updated: 2022/02/03 21:28:44 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_name(char *argv)
{
	int	i;

	i = 0;
	i = ft_strlen(argv);
	if (i < 5)
		error_exit("Error file name!\n", NULL);
	else if (argv[i - 4] != '.' || argv[i - 3] != 'b'
		|| argv[i - 2] != 'e' || argv[i - 1] != 'r')
		error_exit("Error file name!\n", NULL);
}	
