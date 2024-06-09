/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:19:16 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/09 14:01:59 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_queue(t_queue *q)
{
	q->front = 0;
	q->rear = 0;
	q->clcted_c = 0;
}

int	add_queue(t_queue *queue, int x, int y, int distance)
{
	queue->array[queue->rear][0] = x;
	queue->array[queue->rear][1] = y;
	queue->array[queue->rear][2] = distance;
	queue->rear = (queue->rear + 1) % QUEUE_MAX;
	return (1);
}

void	del_queue(t_queue *queue, int *x, int *y, int *distance)
{
	*x = queue->array[queue->front][0];
	*y = queue->array[queue->front][1];
	*distance = queue->array[queue->front][2];
	queue->front = (queue->front + 1) % QUEUE_MAX;
}