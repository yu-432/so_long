/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:59:05 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/06 17:33:33 by yooshima         ###   ########.fr       */
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
	size_t	p_pos_x;
	size_t	p_pos_y;
	int		is_p;
	int		is_c;
	int		is_e;
	int		is_invalid;
	size_t	width;
	size_t	height;
}				t_game;

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
int		check_map(t_game *game);
int		read_map(t_game *game);
int		read_img(t_game *game);
int		key_hook(int key_code, t_game *game);
int		test(void);
int	for_check(t_game *game, int key_code);


#endif