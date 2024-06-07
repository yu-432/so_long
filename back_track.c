/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:23:51 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/07 19:11:09 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int **c2i_map(t_game *game)
{
	size_t x;
	size_t y;
	y = 0;
	int map[game->height][game->width];

	while(y < game->height)
	{
		x = 0;
		while(x < game->width)
		{
			if(game->map[y][x] == 'P')
				map[y][x] = 0;
			else if(game->map[y][x] == 'E')
				map[y][x] = INT_MAX;
			else if(game->map[y][x] == '1')
				map[y][x] = -1;
			else
				map[y][x] = -2;
			x++;
		}
		y++;
	}
	printf("shortest route = %d\n", serch_route(game, map));

	return(0);
}

int	serch_route(t_game *game, int map[game->height][game->width])
{
	size_t	x;
	size_t	y;
	int count;

	count = 0;
	while(1)
	{
		y = 0;
		while(y < game->height)
		{
			x = 0;
			while(x < game->width)
			{
				if((map[y][x] == -2 || map[y][x] == INT_MAX) && ((map[y -1][x] == count)
				|| (map[y +1][x] == count) || (map[y][x -1] == count) || (map[y][x +1] == count)))
				{
					if(map[y][x] == INT_MAX)
						return(count + 1);
					map[y][x] = count + 1;
				}
				x++;
			}
			y++;
		}
		count++;
	}
	return (0);
}
