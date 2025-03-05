/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:28:57 by masmar            #+#    #+#             */
/*   Updated: 2025/02/26 14:22:01 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1280 && y >= 0 && y < 720)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	game_loop(t_game *game)
{
	draw_background(game);
	process_movement(game);
	raycast(game);
	draw_minimap(game);
	return (0);
}

void	process_movement(t_game *game)
{
	double	move_step;
	int		forward;
	int		strafe;
	double	move_x;
	double	move_y;

	move_step = game->player.move_speed;
	forward = game->keys.w - game->keys.s;
	strafe = game->keys.d - game->keys.a;
	move_x = move_step * (forward * game->player.dir_x
			+ strafe * game->player.plane_x);
	move_y = move_step * (forward * game->player.dir_y
			+ strafe * game->player.plane_y);
	if (game->model.map[(int)(game->player.pos_y)]
			[(int)(game->player.pos_x + move_x)] == '0')
		game->player.pos_x += move_x;
	if (game->model.map[(int)(game->player.pos_y + move_y)]
			[(int)(game->player.pos_x)] == '0')
		game->player.pos_y += move_y;
}
