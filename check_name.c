/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:07:22 by cthresh           #+#    #+#             */
/*   Updated: 2022/01/28 15:07:23 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
