/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:04 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/10 16:11:01 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "mlx.h"

int	can_move(t_game *g, int x, int y)
{
	if ((g->map[g->p_pos_y + y][g->p_pos_x + x]) != '1')
	{
		printf("Move count = %zu\n", g->move_count + 1);
		if (g->map[g->p_pos_y + y][g->p_pos_x + x] == 'C')
		{
			g->c_count++;
			g->map[g->p_pos_y + y][g->p_pos_x + x] = '0';
		}
		g->p_pos_x += x;
		g->p_pos_y += y;
		return (1);
	}
	return (0);
}

int	key_hook(int key_code, t_game *g)
{
	if (key_code == ESC_KEY)
		exit(0);
	else if (key_code == W_KEY)
		g->move_count += can_move(g, 0, -1);
	else if (key_code == A_KEY)
		g->move_count += can_move(g, -1, 0);
	else if (key_code == S_KEY)
		g->move_count += can_move(g, 0, 1);
	else if (key_code == D_KEY)
		g->move_count += can_move(g, 1, 0);
	g->key_flag = 1;
	return (1);
}
int	mapping(t_game *g)
{
	size_t	x;
	size_t	y;

	y = 0;
	while(y < g->height)
	{
		x = 0;
		while(x < g->width)
		{
			mlx_put_image_to_window(g->mlx, g->win, g->p_img, g->p_pos_x * T_SIZE, g->p_pos_y * T_SIZE);
			if(g->map[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->c_img, x * T_SIZE, y * T_SIZE);
			else if(g->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->e_img, x * T_SIZE, y * T_SIZE);
			else if(g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->w_img, x * T_SIZE, y * T_SIZE);
			else
				mlx_put_image_to_window(g->mlx, g->win, g->b_img, x * T_SIZE, y * T_SIZE);
			x++;
		}
		y++;
	}
	return (0);
}
int	main_loop(t_game *g)
{
	mlx_key_hook(g->win, &key_hook, g);
	if(g->key_flag == 1)
	{
		mlx_clear_window(g->mlx, g->win);
		mapping(g);
		g->key_flag = 0;
	}
	if(g->map[g->p_pos_y][g->p_pos_x] == 'E' && g->is_c == g->c_count)
	{
		mlx_string_put(g->mlx, g->win, (g->width / 2) * T_SIZE,
			(g->height / 2) * T_SIZE, 0x00FFFFFF, "Goal!!");
		return (1);
	}
	mlx_string_put(g->mlx, g->win, 32, 32, 0x00FFFFFF, ft_itoa(g->move_count));
	return (0);
}

void	init_game(t_game *g)
{
	g->is_p = 0;
	g->is_c = 0;
	g->is_e = 0;
	g->is_invalid = 0;
	g->is_exit = 0;
	g->c_count = 0;
	g->move_count = 0;
	g->key_flag = 1;

}

int main(void)
{
	t_game	g;
	int		m;

	init_game(&g);
	m = read_map(&g);
	route(&g);
	g.mlx = mlx_init();
	read_img(&g);
	g.win = mlx_new_window(g.mlx, g.width * T_SIZE, g.height * T_SIZE, "so_long");
	mlx_loop_hook(g.mlx, &main_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}
