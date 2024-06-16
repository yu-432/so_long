/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:04 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/16 15:56:27 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	put_error_exit(char *str)
{
	ft_fd_printf(2, str);
	exit(1);
}

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
	if (!g.mlx)
		put_error_exit("Error\nMlx init failed\n");
	read_img(&g);
	g.win = mlx_new_window(g.mlx, \
		g.width * T_SIZE, g.height * T_SIZE, "so_long");
	if (!g.win)
		put_error_exit("Error\nMake new window failed\n");
	mlx_loop_hook(g.mlx, &main_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}
