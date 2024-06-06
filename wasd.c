/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:04 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/06 19:01:54 by yooshima         ###   ########.fr       */
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
// 	int		y;

// 	x = 0;
// 	y = 0;
// 	y = 0;
// 	// xpm file to image
// 	ishigaki_img = mlx_xpm_file_to_image(game->mlx, "./ishigaki.xpm", &img_width, &img_height);
// 	shibafu_img = mlx_xpm_file_to_image(game->mlx, "./shibafu.xpm", &img_width, &img_height);

// 	// put image window 
// 	while(map[y])
// 	{
// 		if(map[y] == '\n')
// 		{
// 			y += 64;
// 			x = 0;
// 		}
// 		else if(map[y] == '1')
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win, ishigaki_img, x, y);	
// 			x += 64;
// 		}
// 		else
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win, shibafu_img, x, y);	
// 			x += 64;
// 		}
// 		y++;
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

int	fore_check(int key_code, t_game *game)
{
	int move = 0;
	if(key_code == W_KEY)
	{
		if((game->map[game->p_pos_y - 1][game->p_pos_x]) != '1')
		{
			game->map[game->p_pos_y][game->p_pos_x] = '0';
			game->map[game->p_pos_y - 1][game->p_pos_x] = 'P';
			move = 1;
		}
	}
	else if(key_code == A_KEY)
	{
		if((game->map[game->p_pos_y][game->p_pos_x - 1]) != '1')
		{
			game->map[game->p_pos_y][game->p_pos_x] = '0';
			game->map[game->p_pos_y][game->p_pos_x - 1] = 'P';
			move = 1;

		}
	}
	else if(key_code == S_KEY)
	{
		if((game->map[game->p_pos_y + 1][game->p_pos_x]) != '1')
		{
			game->map[game->p_pos_y][game->p_pos_x] = '0';
			game->map[game->p_pos_y + 1][game->p_pos_x] = 'P';
			move = 1;

		}
	}
	else if(key_code == D_KEY)
	{
		if((game->map[game->p_pos_y][game->p_pos_x + 1]) != '1')
		{
			game->map[game->p_pos_y][game->p_pos_x] = '0';
			game->map[game->p_pos_y][game->p_pos_x + 1] = 'P';
			move = 1;

		}
	}
	return(move);
}

int	key_hook(int key_code, t_game *game)
{
	printf("key press %d\n", key_code);
	printf("%d\n", game->is_c);

	if(key_code == ESC_KEY)
		exit(0);
	else if(key_code == W_KEY)
	{
		if(fore_check(key_code, game))
			game->p_pos_y--;
	}
	else if(key_code == A_KEY)
	{
		if(fore_check(key_code, game))
			game->p_pos_x--;
	}
	else if(key_code == S_KEY)
	{
		if(fore_check(key_code, game))
		game->p_pos_y++;
	}
	else if(key_code == D_KEY)
	{
		if(fore_check(key_code, game))
			game->p_pos_x++;
	}
	g_key_flag = 1;
	return (key_code);
}
int	mouse_hook(int button, int x,int y)
{
	printf("mouse click %d location[%d,%d]\n", button, x, y);
	return (0);
}
int	mapping(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while(y < game->height)
	{
		x = 0;
		while(x < game->width)
		{
			if(game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * 64, y * 64);
			else if(game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img, x * 64, y * 64);
			else if(game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * 64, y * 64);
			else if(game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->background_img, x * 64, y * 64);
			else if(game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}
int	main_loop(t_game *game)
{
	mlx_key_hook(game->win, &key_hook, game);//&game -> game に変更することで値を参照できるようになった
	if(g_key_flag == 1)
	{
		mlx_clear_window(game->mlx, game->win);
		mapping(game);
		g_key_flag = 0;
	}
	return (0);
}


int main(void)
{
	t_game	game;
	int		m;

	m = read_map(&game);
	game.mlx = mlx_init();
	printf("pressey = %p\n", game.mlx);

	read_img(&game);
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "so_long");
	mlx_loop_hook(game.mlx, &main_loop, &game);

	mlx_loop(game.mlx);

	return (0);
}
