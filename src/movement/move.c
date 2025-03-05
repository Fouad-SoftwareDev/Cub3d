/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:19:13 by masmar            #+#    #+#             */
/*   Updated: 2025/02/26 15:06:52 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * game->player.move_speed;
	new_y = game->player.pos_y + game->player.dir_y * game->player.move_speed;
	if (game->model.map[(int)new_y][(int)new_x] == '0')
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * game->player.move_speed;
	new_y = game->player.pos_y - game->player.dir_y * game->player.move_speed;
	if (game->model.map[(int)new_y][(int)new_x] == '0')
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}
