/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:16:27 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/31 16:32:45 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mlx.h"

/*
.berファイルを読み込んでマップを描画する
壁以外は全て背景画像を描画した上にプレイヤーコインゴールを置く
*/

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_hook(int key_hook, t_vars *vars)
{
	printf("key press %d\n", key_hook);
	return (0);
}
int	mouse_hook(int button, int x,int y, t_vars *vars)
{
	printf("mouse click %d location[%d,%d]\n", button, x, y);
	return (0);
}


int main(void)
{
	t_vars	vars;
	t_data	img;
	int		i, j;

	vars.mlx =  mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 600, "yooshima");
	img.img = mlx_new_image(vars.mlx, 1000, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for(i = 0; i < 500; i++)
	{
		for(j = 0; j < 500; j++)
			if(round(sqrt((i-250)*(i-250)+(j-250)*(j-250)))<100)
				my_mlx_pixel_put(&img, i, j, 0x00FFFFFF);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook (vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}


