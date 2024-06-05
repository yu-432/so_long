/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:12:59 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/05 14:46:27 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	count_pce(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while(i < (game->height))
	{
		j = 0;
		while(j < (game->width - 1))
		{
			if((game->map[i][j]) == 'P')
				game->is_p++;
			else if(game->map[i][j] == 'C')
				game->is_c++;
			else if(game->map[i][j] == 'E')
				game->is_e++;
			else if(!ft_strchr("PCE01", game->map[i][j]))
				game->is_invalid++;
			j++;
		}
		i++;
	}
}

bool	check_pce(t_game *game)
{
	bool	is_error;

	is_error = 0;
	if(game->is_p != 1)
	{
		printf("P error%d\n", game->is_p);
		is_error = 1;
	}
	if(game->is_c < 1)
	{
		printf("C error%d\n", game->is_c);
		is_error = 1;
	}
	else if(game->is_e != 1)
	{
		printf("E error\n");
		is_error = 1;
	}
	else if(game->is_invalid != 0)
	{
		printf("invalid error\n");
		is_error = 1;
	}
	return (is_error);
}

//mapが壁で囲われているか
int	check_wall(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while(j < game->width)
	{
		if(game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
			return (0);
		j++;
	}
	while(i < game->height)
	{
		if(game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

//mapが長方形であるか
int	check_rectangle(t_game *game)
{
	int	i;

	i  = 0;
	game->width = ft_strlen(game->map[i]);
	while(game->map[i])
	{
		if(game->width != ft_strlen(game->map[i]))
			break;
		i++;
	}
	game->height = i;
	if(game->height > game->width)
		return(0);
	return(1);
}

int	check_map(t_game *game)
{
	if(!check_rectangle(game))
		printf("Map is not rectangle\n");
	if(!check_wall(game))
		printf("Wall error\n");
	count_pce(game);
	check_pce(game);
	return (0);
}