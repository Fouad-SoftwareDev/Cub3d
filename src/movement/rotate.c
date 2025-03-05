/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:46:58 by masmar            #+#    #+#             */
/*   Updated: 2025/02/20 14:47:44 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(-game->player.rot_speed)
		- game->player.dir_y * sin(-game->player.rot_speed);
	game->player.dir_y = old_dir_x * sin(-game->player.rot_speed)
		+ game->player.dir_y * cos(-game->player.rot_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(-game->player.rot_speed)
		- game->player.plane_y * sin(-game->player.rot_speed);
	game->player.plane_y = old_plane_x * sin(-game->player.rot_speed)
		+ game->player.plane_y * cos(-game->player.rot_speed);
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(game->player.rot_speed)
		- game->player.dir_y * sin(game->player.rot_speed);
	game->player.dir_y = old_dir_x * sin(game->player.rot_speed)
		+ game->player.dir_y * cos(game->player.rot_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(game->player.rot_speed)
		- game->player.plane_y * sin(game->player.rot_speed);
	game->player.plane_y = old_plane_x * sin(game->player.rot_speed)
		+ game->player.plane_y * cos(game->player.rot_speed);
}
