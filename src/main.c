/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:04 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/15 16:42:30 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/*
xpmファイルが存在するかどうかの判定を行ったほうがいいです。存在しない場合にsegvしました。ft_splitの戻り値を確認して処理が成功しているか確認したほうがいいです。mlx_initも失敗する可能性があるので確認するべきです。normやリークの問題はありませんでした。最短経路を求めてスコアを出すための工夫をされていて良かったです。ありがとうございました。
*/

int	close_window(t_game *g)
{
	(void)g;
	exit(0);
}

int	main_loop(t_game *g)
{
	mlx_key_hook(g->win, &key_hook, g);
	make_map(g);
	if (g->map[g->p_y][g->p_x] == 'E' && g->is_c == g->c_count)
	{
		g->is_exit = 1;
		end_game(g);
	}
	mlx_hook(g->win, 17, 1L << 17, close_window, g);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;
	t_queue	q;

	init_game(&g);
	read_map(&g, argv[argc - 1]);
	route(&g, &q);
	g.mlx = mlx_init();
	read_img(&g);
	g.win = mlx_new_window(g.mlx, \
		g.width * T_SIZE, g.height * T_SIZE, "so_long");
	mlx_loop_hook(g.mlx, &main_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}
