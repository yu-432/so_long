/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:19:16 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/14 15:16:08 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/solong_bonus.h"

void	init_queue(t_queue *q)
{
	q->front = 0;
	q->rear = 0;
}

int	add_queue(t_queue *q, int x, int y, int distance)
{
	q->array[q->rear][0] = x;
	q->array[q->rear][1] = y;
	q->array[q->rear][2] = distance;
	q->rear = (q->rear + 1) % QUEUE_MAX;
	return (1);
}

void	pic_queue(t_queue *q, int *x, int *y, int *distance)
{
	*x = q->array[q->front][0];
	*y = q->array[q->front][1];
	*distance = q->array[q->front][2];
	q->front = (q->front + 1) % QUEUE_MAX;
}