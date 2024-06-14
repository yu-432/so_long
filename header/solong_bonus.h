/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:59:05 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/14 17:07:51 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define WIDTH_MAX 40
# define HEIGHT_MAX 22
# define T_SIZE 64
# define WD_SIZE 10
# define LINE_HEIGHT 20
# define QUEUE_MAX 200
# define WHITE 0x00FFFFFF

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
# include "../minilibx_mms/mlx.h"
# include "../ft_fd_printf/ft_fd_printf.h"

typedef struct s_queue
{
	int		array[QUEUE_MAX][3];
	int		cp_map[HEIGHT_MAX][WIDTH_MAX];
	int		v_map[HEIGHT_MAX][WIDTH_MAX];
	int		front;
	int		rear;
	int		clcted_c;
}				t_queue;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*c_img;
	void	*e_img;
	void	*w_img;
	void	*b_img;
	void	*t_img;
	char	**map;
	int		is_p;
	int		is_c;
	int		is_e;
	int		is_invalid;
	int		is_exit;
	int		c_count;
	size_t	p_x;
	size_t	p_y;
	size_t	move_count;
	size_t	bt_distance;
	size_t	width;
	size_t	height;
	bool	key_flag;
	bool	is_move;
}				t_game;

// libft
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// queue
void	init_queue(t_queue *q);
void	pic_queue(t_queue *q, int *x, int *y, int *distance);
int		add_queue(t_queue *q, int x, int y, int distance);
// map
void	c2i_map(t_game *g, t_queue *q);
void	make_map(t_game *g);
void	route(t_game *g, t_queue *q);
void	check_map(t_game *g);
void	read_map(t_game *g, char *filename);
int	can_move(t_game *g, int x, int y);
void	move_ptrl(t_game *g, size_t x, size_t y);

// other
void	put_error(char *s, int fd);
void	init_game(t_game *g);
int		read_img(t_game *g);
int		key_hook(int key_code, t_game *g);
int		end_game(t_game *g);

#endif