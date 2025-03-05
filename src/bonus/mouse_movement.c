/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:19:59 by masmar            #+#    #+#             */
/*   Updated: 2025/03/05 16:42:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle)
		+ game->player.plane_y * cos(angle);
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	last_x;
	int			delta_x;

	(void)y;
	last_x = WIDTH / 2;
	delta_x = x - last_x;
	if (delta_x != 0)
	{
		rotate_player(game, delta_x * 0.0002);
		mlx_mouse_move(game->mlx, game->win,
			WIDTH / 2, HEIGHT / 2);
	}
	last_x = WIDTH / 2;
	return (0);
}
