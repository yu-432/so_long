/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:12:59 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/03 18:53:20 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	count_pce(t_map *map_data)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 1;
	while(i < (map_data->map_height - 1))
	{
		j = 0;
		while(j < (map_data->map_width - 1))
		{
			if((map_data->map[i][j]) == 'P')
				map_data->is_p++;
			else if(map_data->map[i][j] == 'C')
				map_data->is_c++;
			else if(map_data->map[i][j] == 'E')
				map_data->is_e++;
			else if(!ft_strchr("PCE01", map_data->map[i][j]))
				map_data->is_invalid++;
			j++;
		}
		i++;
	}
}

bool	check_pce(t_map *map_data)
{
	bool	is_error;

	is_error = 0;
	if(map_data->is_p != 1)
	{
		printf("P error%d\n", map_data->is_p);
		is_error = 1;
	}
	if(map_data->is_c < 1)
	{
		printf("C error\n");
		is_error = 1;
	}
	else if(map_data->is_e != 1)
	{
		printf("E error\n");
		is_error = 1;
	}
	else if(map_data->is_invalid != 0)
	{
		printf("invalid error\n");
		is_error = 1;
	}
	return (is_error);
}

//mapが壁で囲われているか
int	check_wall(t_map *map_data)
{
	size_t i;
	size_t	j;

	i = 0;
	j = 0;
	while(j < map_data->map_width)
	{
		if(map_data->map[0][j] != '1' || map_data->map[map_data->map_height - 1][j] != '1')
			return (0);
		j++;
	}
	while(map_data->map[i])
	{
		if(map_data->map[i][0] != '1' || map_data->map[i][map_data->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

//mapが長方形であるか
int	check_rectangle(t_map *map_data)
{
	int	i;

	i  = 0;
	map_data->map_width = ft_strlen(map_data->map[i]);
	while(map_data->map[i])
	{
		if(map_data->map_width != ft_strlen(map_data->map[i]))
			return (0);
		i++;
	}
	map_data->map_height = i;
	if(map_data->map_height > map_data->map_width)
		return(0);
	return(1);
}

int	check_map(t_map *map_data)
{
	int	i;

	i = 0;
	if(!check_rectangle(map_data))
		printf("Map is not rectangle\n");
	if(!check_wall(map_data))
		printf("Wall error\n");
	count_pce(map_data);
	if(!check_pce(map_data))
		;

	return (0);
}