/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:59:05 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/09 14:01:36 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define TILE_SIZE 64
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define QUEUE_MAX 200

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include "minilibx_mms/mlx.h"

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	void	*wall_img;
	void	*background_img;
	char	**map;
	int		is_p;
	int		is_c;
	int		is_e;
	int		is_invalid;
	int		is_exit;
	int		c_count;
	size_t	p_pos_x;
	size_t	p_pos_y;
	size_t	move_count;
	size_t	width;
	size_t	height;
	bool	key_flag;
}				t_game;

typedef struct s_queue
{
	int	array[QUEUE_MAX][3];
	int	front;
	int rear;
	int clcted_c;
}				t_queue;


char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
int		check_map(t_game *game);
int		read_map(t_game *game);
int		read_img(t_game *game);
int		key_hook(int key_code, t_game *game);
int **c2i_map(t_game *game, int map[game->height][game->width]);
// int	serch_route(t_game *game, int map[game->height][game->width]);
char	*ft_itoa(int n);
int	route(t_game *game);
void	init_queue(t_queue *q);
int	add_queue(t_queue *queue, int x, int y, int distance);
void	del_queue(t_queue *queue, int *x, int *y, int *distance);






#endif