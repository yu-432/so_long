/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:04 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/12 18:30:44 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	can_move(t_game *g, int x, int y)
{
	if ((g->map[g->p_y + y][g->p_x + x]) != '1')
	{
		ft_fd_printf(2, "Move count = %d\n", (int)g->move_count + 1);
		if (g->map[g->p_y][g->p_x] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, \
				g->e_img, g->p_x * T_SIZE, g->p_y * T_SIZE);
		else
		{
			g->map[g->p_y][g->p_x] = '0';
			mlx_put_image_to_window(g->mlx, g->win, \
				g->b_img, g->p_x * T_SIZE, g->p_y * T_SIZE);
		}
		if (g->map[g->p_y + y][g->p_x + x] == 'C')
			g->c_count++;
		g->p_x += x;
		g->p_y += y;
		return (1);
	}
	return (0);
}

int	key_hook(int key_code, t_game *g)
{
	int	i;

	if (key_code == ESC_KEY)
	{
		i = 0;
		while (g->map[i])
		{
			free(g->map[i]);
			i++;
		}
		free(g->map);
		exit(0);
	}
	else if (key_code == W_KEY && g->is_exit != 1)
		g->move_count += can_move(g, 0, -1);
	else if (key_code == A_KEY && g->is_exit != 1)
		g->move_count += can_move(g, -1, 0);
	else if (key_code == S_KEY && g->is_exit != 1)
		g->move_count += can_move(g, 0, 1);
	else if (key_code == D_KEY && g->is_exit != 1)
		g->move_count += can_move(g, 1, 0);
	g->key_flag = 1;
	return (1);
}



int	main_loop(t_game *g)
{
	char	*move_ptr;

	mlx_key_hook(g->win, &key_hook, g);
	make_map(g);
	move_ptr = ft_itoa(g->move_count);
	mlx_string_put(g->mlx, g->win, 32, 32, WHITE, move_ptr);
	free(move_ptr);
	if (g->map[g->p_y][g->p_x] == 'E' && g->is_c == g->c_count)
	{
		g->is_exit = 1;
		mlx_string_put(g->mlx, g->win, (g->width / 2) * T_SIZE,
			(g->height / 2) * T_SIZE, WHITE, "GOAL!!");
		mlx_string_put(g->mlx, g->win, (g->width / 2) * T_SIZE,
			(g->height / 2) * T_SIZE + 20, WHITE, "PRESS ESC TO END GAME");
		return (1);
	}
	return (0);
}

int	main(void)
{
	t_game	g;
	t_queue	q;

	init_game(&g);
	read_map(&g);
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
    system("leaks -q a.out");
}
