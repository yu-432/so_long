/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:12:59 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/04 14:20:41 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	count_pce(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while(i < (map->height))
	{
		j = 1;
		while(j < (map->width - 1))
		{
			if((map->map[i][j]) == 'P')
				map->is_p++;
			else if(map->map[i][j] == 'C')
				map->is_c++;
			else if(map->map[i][j] == 'E')
				map->is_e++;
			else if(!ft_strchr("PCE01", map->map[i][j]))
				map->is_invalid++;
			j++;
		}
		i++;
	}
}

bool	check_pce(t_map *map)
{
	bool	is_error;

	is_error = 0;
	if(map->is_p != 1)
	{
		printf("P error%d\n", map->is_p);
		is_error = 1;
	}
	if(map->is_c < 1)
	{
		printf("C error%d\n", map->is_c);
		is_error = 1;
	}
	else if(map->is_e != 1)
	{
		printf("E error\n");
		is_error = 1;
	}
	else if(map->is_invalid != 0)
	{
		printf("invalid error\n");
		is_error = 1;
	}
	return (is_error);
}

//mapが壁で囲われているか
int	check_wall(t_map *map)
{
	size_t i;
	size_t	j;

	i = 0;
	j = 0;
	while(j < map->width)
	{
		if(map->map[0][j] != '1' || map->map[map->height][j] != '1')
			return (0);
		j++;
	}
	while(map->map[i])
	{
		if(map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

//mapが長方形であるか
int	check_rectangle(t_map *map)
{
	int	i;

	i  = 0;
	map->width = ft_strlen(map->map[i]);
	while(map->map[i])
	{
		if(map->width != ft_strlen(map->map[i]))
			break;
		i++;
	}
	map->height = i;
	if(map->height > map->width)
		return(0);
	return(1);
}

int	check_map(t_map *map)
{
	if(!check_rectangle(map))
		printf("Map is not rectangle\n");
	if(!check_wall(map))
		printf("Wall error\n");
	count_pce(map);
	check_pce(map);
	return (0);
}

int test(void)
{
	printf("hello\n");
	return(0);
}