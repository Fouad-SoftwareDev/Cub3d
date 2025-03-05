/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strafe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:48:38 by masmar            #+#    #+#             */
/*   Updated: 2025/03/01 00:46:11 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	strafe_left(t_game *game)
{
	double	move_x;
	double	move_y;
	double	new_x;
	double	new_y;

	move_x = -game->player.plane_x * game->player.move_speed;
	move_y = -game->player.plane_y * game->player.move_speed;
	new_x = game->player.pos_x + move_x;
	new_y = game->player.pos_y + move_y;
	if (game->model.map[(int)new_y][(int)new_x] == '0')
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}

void	strafe_right(t_game *game)
{
	double	move_x;
	double	move_y;
	double	new_x;
	double	new_y;

	move_x = game->player.plane_x * game->player.move_speed;
	move_y = game->player.plane_y * game->player.move_speed;
	new_x = game->player.pos_x + move_x;
	new_y = game->player.pos_y + move_y;
	if (game->model.map[(int)new_y][(int)new_x] == '0')
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}
