/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:41:43 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/09 17:56:06 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	read_map(t_game *g)
{
	int		fd;
	int		read_byte;
	char	buf[1001];

	fd = open("maps/map.ber", O_RDONLY);
	if (fd < 0)
		return (0);
	read_byte = read(fd, buf, 1000);
	if (read_byte < 0)
		return (0);
	g->map = ft_split(buf, '\n');
	check_map(g);
	return (1);
}

int	read_img(t_game *g)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	g->p_img = mlx_xpm_file_to_image(g->mlx, "./textures/player.xpm", &width, &height);
	g->c_img = mlx_xpm_file_to_image(g->mlx, "textures/collectible.xpm", &width, &height);
	g->e_img = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm", &width, &height);
	g->w_img = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &width, &height);
	g->b_img = mlx_xpm_file_to_image(g->mlx, "textures/background.xpm", &width, &height);
	return (0);
}
