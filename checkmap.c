/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:12:59 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/11 14:13:22 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	count_pce(t_game *g)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (g->height))
	{
		x = 0;
		while (x < (g->width - 1))
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

bool	check_pce(t_game *g)
{
	bool	is_error;

	is_error = 0;
	if (g->is_p != 1)
	{
		ft_putstr_fd("Invalid MAP: Player error\n", 2);
		is_error = 1;
	}
	if (g->is_c < 1)
	{
		ft_putstr_fd("Invalid MAP: Collectable error\n", 2);
		is_error = 1;
	}
	else if (g->is_e != 1)
	{
		ft_putstr_fd("Invalid MAP: Exit error\n", 2);
		is_error = 1;
	}
	else if (g->is_invalid != 0)
	{
		ft_putstr_fd("Invalid MAP: Invalid Component\n", 2);
		is_error = 1;
	}
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
			return (0);
		j++;
	}
	while (i < g->height)
	{
		if (g->map[i][0] != '1' || g->map[i][g->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_rectangle(t_game *g)
{
	int	i;

	i	= 0;
	g->width = ft_strlen(g->map[i]);
	while (g->map[i])
	{
		if (g->width != ft_strlen(g->map[i]))
			break ;
		i++;
	}
	g->height = i;
	if (g->height > g->width)
		return (0);
	return (1);
}

void	check_map(t_game *g)
{
	if (!check_rectangle(g))
		ft_putstr_fd("Invalid MAP: Not rectangle\n", 2);
	if (!check_wall(g))
		ft_putstr_fd("Invalid MAP: Not enclosed by walls\n", 2);
	count_pce(g);
	if(check_pce(g))
		exit(0);
}