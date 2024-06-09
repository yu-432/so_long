/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:41:43 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/09 14:13:52 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	read_map(t_game *game)
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
	game->map = ft_split(buf, '\n');
	check_map(game);
	return (1);
}

int	read_img(t_game *game)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &width, &height);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &width, &height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
	game->background_img = mlx_xpm_file_to_image(game->mlx, "textures/background.xpm", &width, &height);
	return (0);
}
