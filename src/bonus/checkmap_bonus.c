/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:12:59 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/14 16:49:00 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/solong_bonus.h"

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
			else if (!ft_strchr("PCET01", g->map[y][x]))
				g->is_invalid++;
			x++;
		}
		y++;
	}
}

bool	check_pce(t_game *g)
{
	bool	is_error;

	is_error = 0;
	if (g->is_p != 1)
	{
		ft_fd_printf(2, "Error\nInvalid MAP: Player error\n");
		is_error = 1;
	}
	if (g->is_c < 1)
	{
		ft_fd_printf(2, "Error\nInvalid MAP: Collectable error\n");
		is_error = 1;
	}
	else if (g->is_e != 1)
	{
		ft_fd_printf(2, "Error\nInvalid MAP: Exit error\n");
		is_error = 1;
	}
	else if (g->is_invalid != 0)
	{
		ft_fd_printf(2, "Error\nInvalid MAP: Invalid Component\n");
		is_error = 1;
	}
	return (is_error);
}

bool	check_wall(t_game *g)
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

bool	check_rectangle(t_game *g)
{
	int		i;
	bool	error;

	error = 0;
	i = 0;
	g->width = ft_strlen(g->map[i]);
	while (g->map[i])
	{
		if (g->width != ft_strlen(g->map[i]))
			error = 1;
		i++;
	}
	g->height = i;
	if (g->height > g->width || error)
	{
		ft_fd_printf(2, "Error\nInvalid MAP: Not rectangle\n", 2);
		error = 1;
	}
	return (error);
}

void	check_map(t_game *g)
{
	bool	error;

	error = 0;
	error = check_rectangle(g);
	count_pce(g);
	error = check_pce(g);
	error = check_wall(g);
	if (error)
		exit(1);
}