/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:12:59 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/16 16:10:01 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	count_pce(t_game *g)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (g->height))
	{
		x = 0;
		while (x < (g->width))
		{
			if ((g->map[y][x]) == 'P')
			{
				g->is_p++;
				g->p_x = x;
				g->p_y = y;
			}
			else if (g->map[y][x] == 'C')
				g->is_c++;
			else if (g->map[y][x] == 'E')
				g->is_e++;
			else if (!ft_strchr("PCE01", g->map[y][x]))
				g->is_invalid++;
			x++;
		}
		y++;
	}
}

int	check_pce(t_game *g)
{
	int	is_error;

	is_error = 0;
	if (g->is_p != 1)
		is_error = ft_fd_printf(2, "Error\nInvalid MAP: Player error\n");
	if (g->is_c < 1)
		is_error = ft_fd_printf(2, "Error\nInvalid MAP: Collectable error\n");
	else if (g->is_e != 1)
		is_error = ft_fd_printf(2, "Error\nInvalid MAP: Exit error\n");
	else if (g->is_invalid != 0)
		is_error = ft_fd_printf(2, "Error\nInvalid MAP: Invalid Component\n");
	return (is_error);
}

int	check_wall(t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < g->width)
	{
		if (g->map[0][j] != '1' || g->map[g->height - 1][j] != '1')
		{
			ft_fd_printf(2, "Error\nInvalid MAP: Horizontal walls error\n");
			return (1);
		}
		j++;
	}
	while (i < g->height)
	{
		if (g->map[i][0] != '1' || g->map[i][g->width - 1] != '1')
		{
			ft_fd_printf(2, "Error\nInvalid MAP: Vertical walls error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_rectangle(t_game *g)
{
	int	i;
	int	error;

	g->width = ft_strlen(g->map[i]);
	i = 0;
	error = 0;
	while (g->map[i])
	{
		if (g->width != ft_strlen(g->map[i]))
			error = 1;
		i++;
	}
	g->height = i;
	if (g->width > WIDTH_MAX || g->height > HEIGHT_MAX)
		put_error_exit("Error\nMap is too big\n");
	if (g->height > g->width || error)
	{
		ft_fd_printf(2, "Error\nInvalid MAP: Not rectangle\n", 2);
		error = 1;
	}
	return (error);
}

void	check_map(t_game *g)
{
	int	error;

	error = 0;
	error += check_rectangle(g);
	count_pce(g);
	error += check_pce(g);
	error += check_wall(g);
	if (error != 0)
		exit(1);
}
