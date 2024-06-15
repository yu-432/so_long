/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:59:45 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/15 12:44:00 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

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

void	my_mlx_string_put(t_game *g, char *str, int v_offset)
{
	int	width;
	int	h_offset;

	width = g->width * T_SIZE / 2;
	h_offset = ft_strlen(str) / 2 * WD_SIZE;
	mlx_string_put(g->mlx, g->win, width - h_offset, \
		(g->height) / 2 * T_SIZE + v_offset * LINE_HEIGHT, WHITE, str);
}

int	end_game(t_game *g)
{
	char	*temp;

	temp = ft_itoa(g->bt_distance * 999999 / g->move_count);
	my_mlx_string_put(g, "GOAL!!", 0);
	my_mlx_string_put(g, "YOUR SCORE", 1);
	my_mlx_string_put(g, temp, 2);
	my_mlx_string_put(g, "PRESS ESC TO END GAME", 3);
	free(temp);
	return (0);
}
