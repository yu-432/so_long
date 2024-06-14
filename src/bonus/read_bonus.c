/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:41:43 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/14 16:58:28 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/solong_bonus.h"

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
	g->is_move = 0;
}

int	check_fname(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
			break ;
		i++;
	}
	return (ft_strncmp(&filename[i], ".ber", 5));
}

void	read_map(t_game *g, char *filename)
{
	int		fd;
	int		read_byte;
	char	buf[1001];

	if (check_fname(filename))
	{
		ft_fd_printf(2, "Error\nInvalid Filename\n");
		exit(1);
	}
	fd = open(filename, O_RDONLY);
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
	g->p_img = mlx_xpm_file_to_image(g->mlx, "textures/mandatory/p.xpm", &width, &height);
	g->c_img = mlx_xpm_file_to_image(g->mlx, "textures/mandatory/c.xpm", &width, &height);
	g->e_img = mlx_xpm_file_to_image(g->mlx, "textures/mandatory/e.xpm", &width, &height);
	g->w_img = mlx_xpm_file_to_image(g->mlx, "textures/mandatory/1.xpm", &width, &height);
	g->b_img = mlx_xpm_file_to_image(g->mlx, "textures/mandatory/0.xpm", &width, &height);
	g->t_img = mlx_xpm_file_to_image(g->mlx, "textures/bonus/y.xpm", &width, &height);
	return (0);
}
