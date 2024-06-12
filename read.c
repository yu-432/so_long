/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:41:43 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/12 13:15:41 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_game(t_game *g)
{
	g->is_p = 0;
	g->is_c = 0;
	g->is_e = 0;
	g->is_invalid = 0;
	g->is_exit = 0;
	g->c_count = 0;
	g->move_count = 0;
	g->key_flag = 1;
}

void	read_map(t_game *g)
{
	int		fd;
	int		read_byte;
	char	buf[1001];

	fd = open("maps/map.ber", O_RDONLY);
	if (fd < 0)
	{
		perror(NULL);
		exit(0);
	}
	read_byte = read(fd, buf, 1000);
	if (read_byte < 0)
	{
		perror(NULL);
		exit(0);
	}
	buf[read_byte] = '\0';
	g->map = ft_split(buf, '\n');
	check_map(g);
}

int	read_img(t_game *g)
{
	int	width;
	int	height;

	width = T_SIZE;
	height = T_SIZE;
	g->p_img = mlx_xpm_file_to_image(g->mlx, "textures/p.xpm", &width, &height);
	g->c_img = mlx_xpm_file_to_image(g->mlx, "textures/c.xpm", &width, &height);
	g->e_img = mlx_xpm_file_to_image(g->mlx, "textures/e.xpm", &width, &height);
	g->w_img = mlx_xpm_file_to_image(g->mlx, "textures/1.xpm", &width, &height);
	g->b_img = mlx_xpm_file_to_image(g->mlx, "textures/0.xpm", &width, &height);
	return (0);
}
