/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:04 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/09 15:25:27 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "mlx.h"

int	can_move(t_game *game, int x, int y)
{
	if ((game->map[game->p_pos_y + y][game->p_pos_x + x]) != '1')
	{
		if (game->map[game->p_pos_y + y][game->p_pos_x + x] == 'C')
			game->c_count++;
		if (game->map[game->p_pos_y + y][game->p_pos_x + x] == 'E')
			game->is_exit = 1;
		game->map[game->p_pos_y][game->p_pos_x] = '0';
		game->map[game->p_pos_y + y][game->p_pos_x + x] = 'P';
		game->p_pos_x += x;
		game->p_pos_y += y;
		printf("Move count = %zu\n", game->move_count);
		return (1);
	}
	return (0);
}

int	key_hook(int key_code, t_game *game)
{
	if (key_code == ESC_KEY)
		exit(0);
	else if (key_code == W_KEY)
		game->move_count += can_move(game, 0, -1);
	else if (key_code == A_KEY)
		game->move_count += can_move(game, -1, 0);
	else if (key_code == S_KEY)
		game->move_count += can_move(game, 0, 1);
	else if (key_code == D_KEY)
		game->move_count += can_move(game, 1, 0);
	game->key_flag = 1;
	return (1);
}
int	mapping(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while(y < game->height)
	{
		x = 0;
		while(x < game->width)
		{
			if(game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
			else if(game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img, x * TILE_SIZE, y * TILE_SIZE);
			else if(game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
			else if(game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->background_img, x * TILE_SIZE, y * TILE_SIZE);
			else if(game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	return (0);
}
int	main_loop(t_game *game)
{
	mlx_key_hook(game->win, &key_hook, game);
	mlx_string_put(game->mlx, game->win, 32, 32, 0x00FFFFFF, ft_itoa(game->move_count));	
	if(game->key_flag == 1)
	{
		mlx_clear_window(game->mlx, game->win);
		mapping(game);
		game->key_flag = 0;
		for(int i = 0; game->map[i] != 0; i++)
		{
			for(int j = 0; game->map[i][j] != 0; j++)
			{
				printf("%c", game->map[i][j]);
			}
			printf("\n");
		}
	}
	if(game->is_exit)
	{
		mlx_string_put(game->mlx, game->win, (game->width / 2) * TILE_SIZE,
			(game->height / 2) * TILE_SIZE, 0x00FFFFFF, "Goal!!");
			return (1);
	}
	return (0);
	
}

void	init_game(t_game *game)
{
	game->is_p = 0;
	game->is_c = 0;
	game->is_e = 0;
	game->is_invalid = 0;
	game->is_exit = 0;
	game->c_count = 0;
	game->move_count = 0;
	game->key_flag = 1;

}


int main(void)
{
	t_game	game;
	int		m;

	init_game(&game);
	m = read_map(&game);
	route(&game);
	game.mlx = mlx_init();
	read_img(&game);
	game.win = mlx_new_window(game.mlx, game.width * TILE_SIZE, game.height * TILE_SIZE, "so_long");
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);

	return (0);
}
