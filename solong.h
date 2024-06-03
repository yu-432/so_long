/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:59:05 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/03 17:56:36 by yooshima         ###   ########.fr       */
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


typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_game;


typedef struct	s_map
{
	char **map;
	int	is_p;
	int	is_c;
	int	is_e;
	int	is_invalid;
	size_t	map_width;
	size_t	map_height;
}				t_map;

char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		read_map(void);
size_t	ft_strlen(const char *s);
int		check_map(t_map *map_data);
char	*ft_strchr(const char *s, int c);





#endif