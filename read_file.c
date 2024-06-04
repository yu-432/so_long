/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:41:43 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/04 14:39:27 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	read_map(t_map *map)
{
	int		fd;
	int		read_byte;
	char	buf[1001];

	fd = open("maps/map.ber", O_RDONLY);
	if(fd < 0)
		return (0);
	read_byte = read(fd, buf, 1000);
	if(read_byte < 0)
		return(0);
	map->map = ft_split(buf, '\n');
		// map描画チェック
	for(int i = 0; map->map[i] != 0; i++)
	{
		for(int j = 0; map->map[i][j] != 0; j++)
		{
			printf("%c", map->map[i][j]);
		}
		printf("\n");
	}
	check_map(map);
	return (1);
}

int	read_img(t_img *img, t_game *game)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	//ココの下で処理が止まっている
	img->player_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &width, &height);
	img->collect_img = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &width, &height);
	img->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &width, &height);
	img->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
	img->background_img = mlx_xpm_file_to_image(game->mlx, "textures/background.xpm", &width, &height);
	return (0);
}
