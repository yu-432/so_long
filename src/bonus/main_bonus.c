/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:04 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/14 16:26:20 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/solong_bonus.h"

int	close_window(t_game *g)
{
	(void)g;
	exit(0);
}

int	main_loop(t_game *g)
{
	char	*move_count_ptr;

	mlx_key_hook(g->win, &key_hook, g);
	make_map(g);
	move_count_ptr = ft_itoa(g->move_count);
	mlx_string_put(g->mlx, g->win, T_SIZE / 2, T_SIZE / 2, WHITE, move_count_ptr);
	free(move_count_ptr);
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

__attribute__((destructor))
static void destructor() {
    system("leaks -q so_long");
}
