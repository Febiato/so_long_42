/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:26:42 by cthresh           #+#    #+#             */
/*   Updated: 2022/02/03 21:26:44 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../mlx_linux/mlx.h"

typedef struct s_map
{
	char	*map_arr;
	int		map_len;
	int		map_width;
	int		max_score;
	int		vektor;
	int		enemy_flag;
	int		speed;
	int		pos;
	int		steps;
}	t_map;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		fd;
	int		addr;
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_image {
	char	*kartman_zlo;
	char	*kartman;
	char	*kyle_front;
	char	*kyle_back;
	char	*kyle_left;
	char	*kyle_right;
	char	*exit;
	char	*exit_finish;
	char	*wall;
	char	*coin;
	char	*free;
	char	*enemy;
	char	*snow;
	char	*steps;
}				t_image;

typedef struct s_items {
	int		player;
	int		coin;
	int		exit;
	int		fail;
	int		empty;
}				t_items;

typedef struct s_game {
	t_data	param;
	t_image	images;
	t_map	map;
	t_items	items;
}				t_game;

size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	read_file(t_game *game);
void	check_map(t_game *game);
int		check_wall(char *map, int len);
int		map_len(char *map);
void	item_check(t_game *game);
int		map_width(char *map, int len);
void	ft_error(t_game *game);
void	error_exit(char *str, char *memory);
void	check_name(char *argv);
void	ft_putmap(t_game *game, t_data *param, t_map *map);
void	ft_visual(t_game *game);
void	ft_right(t_image *images, t_data *param, t_map *map, t_items *items);
void	ft_left(t_image *images, t_data *param, t_map *map, t_items *items);
void	ft_down(t_image *images, t_data *param, t_map *map, t_items *items);
void	ft_up(t_image *images, t_data *param, t_map *map, t_items *items);
void	ft_exit_finish(t_image *images, t_data *param, t_map *map);
int		ft_enemy(t_game *game);
void	ft_insteps(t_game *game);
char	*ft_itoa_long(t_game *game);
void	ft_clear_steps(t_game *game);
void	ft_put_enemy(t_game *game);
int		destroy_exit(t_game *game);

#endif
