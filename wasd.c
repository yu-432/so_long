/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:04 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/03 17:32:30 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "mlx.h"

int g_player_x = 0;
int	g_player_y = 0;
int	g_key_flag = 1;
int		img_width = 64;
int		img_height = 64;


// int my_rec_put(t_game *game, int x, int y, int color)
// {
// 	int x_end = x + 64;
// 	int y_end = y + 64;
// 	int y_tmp = y;

// 	while(x <= x_end)
// 	{
// 		y = y_tmp;
// 		while(y <= y_end)
// 		{
// 			mlx_pixel_put(game->mlx, game ->win, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (0);
// }

// int	main_loop(t_game *game)
// {
// 	void	*player_img;

// 	player_img = mlx_xpm_file_to_image(game->mlx, "./slime.xpm", &img_width, &img_height);
// 	if(g_key_flag == 1)
// 	{
// 		mlx_put_image_to_window(game->mlx, game->win, player_img, g_player_x, g_player_y);
// 		// mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
// 		// my_rec_put(game, g_player_x, g_player_y, 0x00FFFFFF);
// 	}
// 	g_key_flag = 0;
// 	return (0);
// }

// int	press_key(int key_code, t_game *game)
// {
// 	void	*shibafu_img;

// 	shibafu_img = mlx_xpm_file_to_image(game->mlx, "./shibafu.xpm", &img_width, &img_height);

// 	printf("key press %d\n", key_code);
// 	if(key_code == ESC_KEY)
// 		exit(0);
// 	else if(key_code == W_KEY)
// 	{
// 			mlx_put_image_to_window(game->mlx, game->win, shibafu_img, g_player_x, g_player_y);	
// 			g_player_y -= 64;
// 	}
// 	else if(key_code == A_KEY)
// 	{
// 			mlx_put_image_to_window(game->mlx, game->win, shibafu_img, g_player_x, g_player_y);	
// 			g_player_x -= 64;
// 	}
// 	else if(key_code == S_KEY)
// 	{
// 			mlx_put_image_to_window(game->mlx, game->win, shibafu_img, g_player_x, g_player_y);	
// 			g_player_y += 64;
// 	}
// 	else if(key_code == D_KEY)
// 	{
// 			mlx_put_image_to_window(game->mlx, game->win, shibafu_img, g_player_x, g_player_y);	
// 			g_player_x += 64;
// 	}
// 	g_key_flag = 1;
// 	return (0);
// }
// int	mouse_hook(int button, int x,int y)
// {
// 	printf("mouse click %d location[%d,%d]\n", button, x, y);
// 	return (0);
// }

// int	put_img(t_game *game, char *map)
// {
// 	void	*ishigaki_img;
// 	void	*shibafu_img;

// 	int		x;
// 	int		y;
// 	int		i;

// 	x = 0;
// 	y = 0;
// 	i = 0;
// 	// xpm file to image
// 	ishigaki_img = mlx_xpm_file_to_image(game->mlx, "./ishigaki.xpm", &img_width, &img_height);
// 	shibafu_img = mlx_xpm_file_to_image(game->mlx, "./shibafu.xpm", &img_width, &img_height);

// 	// put image window 
// 	while(map[i])
// 	{
// 		if(map[i] == '\n')
// 		{
// 			y += 64;
// 			x = 0;
// 		}
// 		else if(map[i] == '1')
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win, ishigaki_img, x, y);	
// 			x += 64;
// 		}
// 		else
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win, shibafu_img, x, y);	
// 			x += 64;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

/*
readしたテキストファイルをft_splitで２次元配列にすることでマップを作成


1プログラム実行時
画像の読み込み
mlxの初期化
イベントの登録

２ループ
プレイヤーの移動
プレイヤーの描画
ディスプレイの更新

３イベント
キーボード状態を取得
ディスプレイの状態を取得

minilibx
X window systemを簡単に使うためのライブラリ

*/

// void	mainloop(t_game *game)
// {

// 	game->mlx = mlx_init();
// 	// mlx make new window
// 	game->win = mlx_new_window(game->mlx, width, height, "yooshima");
// 	// ??
// 	game->img.img = mlx_new_image(game->mlx, width, height);
// 	put_img(&game, map);
// 	// if presskey move or nothing
// 	mlx_key_hook(game->win, press_key, &game);
// 	// if mouse click
// 	mlx_mouse_hook (game->win, mouse_hook, &game);
// 	// print Player
// 	mlx_loop_hook(game->mlx, &main_loop, &game);
// 	mlx_loop(game->mlx);
// }

int main(void)
{
	t_map 	map_data;
	int		map;

	// berファイルを読み込み２次元配列のマップを作成
	map = read_map();
	for(int i = 0; map_data.map != 0; i++)
	{
		for(int j = 0; map_data.map[i][j] != '\0'; j++)
		{
			printf("%c", map_data.map[i][j]);
		}
		printf("\n");
	}
	return (0);
}
