/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:06:33 by cthresh           #+#    #+#             */
/*   Updated: 2022/01/28 15:06:36 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*orig;
	size_t		i;

	d = dst;
	orig = src;
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && orig[i] != '\0')
		{
			d[i] = orig[i];
			i++;
		}
		d[i] = '\0';
	}
	dstsize = 0;
	while (orig[dstsize] != '\0')
		dstsize++;
	return (dstsize);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	int		i;

	i = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	if (s1 != NULL)
		i = ft_strlcpy_gnl(s3, s1, (int)ft_strlen(s1) + 1);
	if (s2 != NULL)
		i = ft_strlcpy_gnl(&s3[i], s2,
				(int)ft_strlen(s2) + (int)ft_strlen(s1) + 1);
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
	return (s3);
}

void	read_file(t_game *game)
{
	int		i;
	char	buffer[2];

	i = 0;
	while (i != -1)
	{
		i = read(game->param.fd, buffer, 1);
		if (i <= 0)
			break ;
		buffer[1] = '\0';
		if (buffer[0] == '\0')
			i = -1;
		game->map.map_arr = ft_strjoin_gnl(game->map.map_arr, &buffer[0]);
		if (game->map.map_arr == NULL)
			error_exit("Memory error!\n", NULL);
	}
	check_map(game);
	close(game->param.fd);
}
