/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:23:51 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/09 15:47:46 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	**c2i_map(t_game *game, int v_map[game->height][game->width])
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				v_map[y][x] = 1;
			else if (game->map[y][x] == 'C')
				v_map[y][x] = 2;
			else
				v_map[y][x] = -1;
			x++;
		}
		y++;
	}
	return (0);
}

// int	new_map(t_queue *queue, t_game *game, int v_map[game->height][game->width])
// {
// 	c2i_map(game, v_map);
// 	// printf("p pos = %zu, %zu\n", game->p_pos_x, game->p_pos_y);
// 	add_queue(queue, game->p_pos_x, game->p_pos_y, 0);
// 	return (1);
// }

int	serch_route_q(t_game *game, t_queue *queue, int v_map[game->height][game->width])
{
	int	x;
	int	y;
	int	distance;

	add_queue(queue, game->p_pos_x, game->p_pos_y, 0);
	while (queue->front != queue->rear)
	{
		del_queue(queue, &x, &y, &distance);
		if (game->map[y][x] == 'E')
			return (distance);
		if (v_map[y][x + 1] != 1)
			v_map[y][x + 1] = add_queue(queue, x + 1, y, distance + 1);
		if (v_map[y][x - 1] != 1)
			v_map[y][x - 1] = add_queue(queue, x - 1, y, distance + 1);
		if (v_map[y + 1][x] != 1)
			v_map[y + 1][x] = add_queue(queue, x, y + 1, distance + 1);
		if (v_map[y - 1][x] != 1)
			v_map[y - 1][x] = add_queue(queue, x, y - 1, distance + 1);
	}
	return (0);
}

int	route(t_game *game)
{
	int		v_map[game->height][game->width];
	t_queue	queue;

	c2i_map(game, v_map);
	init_queue(&queue);
	printf("distance = %d\n", serch_route_q(game, &queue, v_map));
	return (0);
}
