/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:04 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/31 18:06:46 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"

# define TILE_SIZE 64
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

int g_player_x = 5;
int	g_player_y = 5;
int	g_key_flag = 1;

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


int my_rec_put(t_game *game, int x, int y, int color)
{
	int x_end = x + 10;
	int y_end = y + 10;
	int y_tmp = y;

	while(x <= x_end)
	{
		y = y_tmp;
		while(y <= y_end)
		{
			mlx_pixel_put(game->mlx, game ->win, x, y, color);
			y++;
		}
		x++;
	}
	return (0);
}

int	main_loop(t_game *game)
{
	if(g_key_flag == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
		my_rec_put(game, g_player_x, g_player_y, 0x00FFFFFF);
	}
	g_key_flag = 0;
	return (0);
}

int	press_key(int key_code, t_game *game)
{
	printf("key press %d\n", key_code);
	if(key_code == ESC_KEY)
		exit(0);
	else if(key_code == W_KEY)
		g_player_y -= 10;
	else if(key_code == A_KEY)
		g_player_x -= 10;
	else if(key_code == S_KEY)
		g_player_y += 10;
	else if(key_code == D_KEY)
		g_player_x += 10;
	g_key_flag = 1;
	return (0);
}
int	mouse_hook(int button, int x,int y, t_game *game)
{
	printf("mouse click %d location[%d,%d]\n", button, x, y);
	return (0);
}

int main(void)
{
	t_game	game;
	size_t	width;
	size_t	height;

	width = 15 * TILE_SIZE;
	height = 10 * TILE_SIZE;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, width, height, "yooshima");
	game.img.img = mlx_new_image(game.mlx, width, height);
	game.img.data = (int *)mlx_get_data_addr(game.img.img, &game.img.bpp, &game.img.size_l, &game.img.endian);
	mlx_key_hook(game.win, press_key, &game);
	mlx_mouse_hook (game.win, mouse_hook, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
