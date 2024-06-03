/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:41:43 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/03 17:37:44 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	reset_mapdata(t_map *map_data)
{
	map_data->is_p = 0;
	map_data->is_c = 0;
	map_data->is_e = 0;
}

int	read_map(void)
{
	int		fd;
	int		read_byte;
	char	buf[1001];
	t_map 	map_data;

	fd = open("./maps/map.ber", O_RDONLY);
	if(fd < 0)
		return (0);
	read_byte = read(fd, buf, 1000);
	if(read_byte < 0)
		return(0);
	map_data.map = ft_split(buf, '\n');
	reset_mapdata(&map_data);
	check_map(&map_data);
	return (1);
}