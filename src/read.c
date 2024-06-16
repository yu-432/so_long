/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:41:43 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/16 15:53:55 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

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
		put_error_exit("Error\nInvalid Filename\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_error_exit("Error\nNo such file or directory\n");
	read_byte = read(fd, buf, 1000);
	if (read_byte < 0)
		put_error_exit("Error\nCan't read file\n");
	buf[read_byte] = '\0';
	g->map = ft_split(buf, '\n');
	if (!g->map)
		put_error_exit("Error\nft_split failed\n");
	check_map(g);
}

void	*my_mlx_xpm_file_to_image(void *mlx, char *filename)
{
	int		fd;
	int		size;
	void	*img;

	size = T_SIZE;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_fd_printf(2, "Error\nNo exist %s file\n", filename);
		exit(1);
	}
	close(fd);
	img = mlx_xpm_file_to_image(mlx, filename, &size, &size);
	if (!img)
	{
		ft_fd_printf(2, "Error\nFailed create %s\n", filename);
		exit(1);
	}
	return (img);
}

int	read_img(t_game *g)
{
	g->p_img = my_mlx_xpm_file_to_image(g->mlx, "textures/p.xpm");
	g->c_img = my_mlx_xpm_file_to_image(g->mlx, "textures/c.xpm");
	g->e_img = my_mlx_xpm_file_to_image(g->mlx, "textures/e.xpm");
	g->w_img = my_mlx_xpm_file_to_image(g->mlx, "textures/1.xpm");
	g->b_img = my_mlx_xpm_file_to_image(g->mlx, "textures/0.xpm");
	return (0);
}
