/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrl_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:28:52 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/14 17:18:45 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/solong_bonus.h"
//01マップを作成してパトロール移動専用とする必要？
//パトロールがコインに触れるとコインが消失してしまう
//基本実装部分は一旦終わったと思う。
void	move_ptrl(t_game *g, size_t x, size_t y)
{
	if (g->is_move)
	{
		g->map[y][x] = '0';
		if(g->p_x < x && g->map[y][x - 1] != '1')
		{
			g->map[y][x - 1] = 'T';
			mlx_put_image_to_window(g->mlx, g->win, \
				g->t_img, (x - 1) * T_SIZE, y * T_SIZE);
		}
		g->is_move = 0;
	}
	else
		mlx_put_image_to_window(g->mlx, g->win, \
			g->t_img, x * T_SIZE, y * T_SIZE);
}