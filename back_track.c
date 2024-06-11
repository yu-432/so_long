/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:23:51 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/11 16:07:03 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	**c2i_map(t_game *g, t_queue *q)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (g->map[y][x] == '1')
				q->cp_map[y][x] = 1;
			else if (g->map[y][x] == 'C')
				q->cp_map[y][x] = 2;
			else if (g->map[y][x] == 'P')
				q->cp_map[y][x] = 0;
			else if (g->map[y][x] == 'E')
				q->cp_map[y][x] = INT_MAX;
			else
				q->cp_map[y][x] = -1;
			x++;
		}
		y++;
	}
	return (0);
}

void	init_map(t_queue *q)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT_MAX)
	{
		j = 0;
		while (j < WIDTH_MAX)
		{
			if (q->cp_map[i][j] == 1)
				q->v_map[i][j] = 1;
			else
				q->v_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	get_coin(t_queue *q, int x, int y, int distance)
{
	q->cp_map[y][x] = -1;
	q->clcted_c++;
	init_queue(q);
	init_map(q);
	add_queue(q, x, y, distance);
	pic_queue(q, &x, &y, &distance);
}

int	serch_route_q(t_game *g, t_queue *q)
{
	int	x;
	int	y;
	int	distance;

	add_queue(q, g->p_x, g->p_y, 0);
	distance = 0;
	while (1)
	{
		pic_queue(q, &x, &y, &distance);
		if (q->cp_map[y][x] == 2)
			get_coin(q, x, y, distance);
		if (g->map[y][x] == 'E' && g->is_c == q->clcted_c)
			return (distance);
		if (q->v_map[y][x + 1] != 1)
			q->v_map[y][x + 1] = add_queue(q, x + 1, y, distance + 1);
		if (q->v_map[y][x - 1] != 1)
			q->v_map[y][x - 1] = add_queue(q, x - 1, y, distance + 1);
		if (q->v_map[y + 1][x] != 1)
			q->v_map[y + 1][x] = add_queue(q, x, y + 1, distance + 1);
		if (q->v_map[y - 1][x] != 1)
			q->v_map[y - 1][x] = add_queue(q, x, y - 1, distance + 1);
		if (q->front == q->rear)
			break ;
	}
	return (0);
}

int	route(t_game *g, t_queue *q)
{
	c2i_map(g, q);
	init_map(q);
	init_queue(q);
	q->clcted_c = 0;
	printf("distance = %d\n", serch_route_q(g, q));
	return (0);
}
