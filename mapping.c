/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:29:16 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/13 12:13:24 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	put_map(t_game *g, size_t x, size_t y)
{
	if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, \
			g->c_img, x * T_SIZE, y * T_SIZE);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, \
			g->e_img, x * T_SIZE, y * T_SIZE);
	else if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, \
			g->w_img, x * T_SIZE, y * T_SIZE);
	else
		mlx_put_image_to_window(g->mlx, g->win, \
			g->b_img, x * T_SIZE, y * T_SIZE);
}

void	make_map(t_game *g)
{
	size_t	x;
	size_t	y;

	if (g->is_exit)
		return ;
	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			put_map(g, x, y);
			mlx_put_image_to_window(g->mlx, g->win, \
				g->p_img, g->p_x * T_SIZE, g->p_y * T_SIZE);
			x++;
		}
		y++;
	}
	return ;
}