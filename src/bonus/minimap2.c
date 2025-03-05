/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:33:22 by masmar            #+#    #+#             */
/*   Updated: 2025/03/03 10:49:08 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	process_minimap_pixel(t_game *game, t_mmap m, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(m.vsx + (x / (double)MINIMAP_CELL_SIZE));
	map_y = (int)floor(m.vsy + (y / (double)MINIMAP_CELL_SIZE));
	if (map_x < 0 || map_x >= game->model.maxwidth)
		my_mlx_pixel_put(&game->img, m.off_x
			+ x, m.off_y + y, OUT_OF_BOUNDS_COLOR);
	else if (map_y < 0 || map_y >= get_map_height(game->model.map))
		my_mlx_pixel_put(&game->img, m.off_x
			+ x, m.off_y + y, OUT_OF_BOUNDS_COLOR);
	else if (game->model.map[map_y][map_x] == '1')
		my_mlx_pixel_put(&game->img, m.off_x + x, m.off_y + y, 0x000000);
	else
		my_mlx_pixel_put(&game->img, m.off_x + x, m.off_y + y, 0xFFFFFF);
}

void	draw_minimap_bg(t_game *game, t_mmap m)
{
	int		x;
	int		y;

	m.vsx = game->player.pos_x - (MINIMAP_VIEWPORT_SIZE / 2.0);
	m.vsy = game->player.pos_y - (MINIMAP_VIEWPORT_SIZE / 2.0);
	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_WIDTH)
		{
			process_minimap_pixel(game, m, x, y);
			x++;
		}
		y++;
	}
}

void	draw_player_on_minimap(t_game *game, t_mmap m)
{
	t_point	player_pos;
	t_point	dir_end;
	int		px;
	int		py;

	player_pos.x = m.off_x + (MINIMAP_WIDTH / 2);
	player_pos.y = m.off_y + (MINIMAP_HEIGHT / 2);
	py = -2;
	while (py <= 2)
	{
		px = -2;
		while (px <= 2)
		{
			my_mlx_pixel_put(&game->img, player_pos.x + px,
				player_pos.y + py, 0xFF0000);
			px++;
		}
		py++;
	}
	dir_end.x = player_pos.x + (int)(game->player.dir_x * 7);
	dir_end.y = player_pos.y + (int)(game->player.dir_y * 7);
	draw_line(game, player_pos, dir_end, 0xFF0000);
}

void	draw_minimap(t_game *game)
{
	t_mmap	m;

	m.off_x = 10;
	m.off_y = 10;
	draw_minimap_bg(game, m);
	draw_player_on_minimap(game, m);
}
