/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:47:35 by masmar            #+#    #+#             */
/*   Updated: 2025/03/05 16:12:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	initflags(t_model *mod)
{
	mod->c = 0;
	mod->f = 0;
	mod->ntex = 0;
	mod->stex = 0;
	mod->etex = 0;
	mod->wtex = 0;
	mod->no = NULL;
	mod->so = NULL;
	mod->we = NULL;
	mod->ea = NULL;
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->screen_width = 1280;
	game->screen_height = 720;
	game->win = mlx_new_window(game->mlx, game->screen_width,
			game->screen_height, "cub3d");
	game->mouse_last_x = game->screen_width / 2;
	if (!game->win)
		return (0);
	game->img.img = mlx_new_image(game->mlx, game->screen_width,
			game->screen_height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	return (1);
}

static void	set_player_direction(t_game *game, char dir)
{
	if (dir == 'E')
		game->player.dir_x = 1;
	else if (dir == 'W')
		game->player.dir_x = -1;
	else
		game->player.dir_x = 0;
	if (dir == 'S')
		game->player.dir_y = 1;
	else if (dir == 'N')
		game->player.dir_y = -1;
	else
		game->player.dir_y = 0;
}

static void	set_player_plane(t_game *game, char dir)
{
	if (dir == 'N')
		game->player.plane_x = 0.66;
	else if (dir == 'S')
		game->player.plane_x = -0.66;
	else
		game->player.plane_x = 0;
	if (dir == 'E')
		game->player.plane_y = 0.66;
	else if (dir == 'W')
		game->player.plane_y = -0.66;
	else
		game->player.plane_y = 0;
}

void	init_player(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (game->model.map[++y])
	{
		x = -1;
		while (game->model.map[y][++x])
		{
			c = game->model.map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
				set_player_direction(game, c);
				set_player_plane(game, c);
				game->model.map[y][x] = '0';
			}
		}
	}
	game->player.move_speed = 0.08;
	game->player.rot_speed = 0.08;
}
