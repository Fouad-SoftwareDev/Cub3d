/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:19:01 by masmar            #+#    #+#             */
/*   Updated: 2025/02/26 14:20:06 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 119)
		game->keys.w = 1;
	if (keycode == 97)
		game->keys.a = 1;
	if (keycode == 115)
		game->keys.s = 1;
	if (keycode == 100)
		game->keys.d = 1;
	if (keycode == 65363)
	{
		rotate_left(game);
		game->keys.left = 1;
	}
	if (keycode == 65361)
	{
		rotate_right(game);
		game->keys.right = 1;
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 119)
		game->keys.w = 0;
	if (keycode == 97)
		game->keys.a = 0;
	if (keycode == 115)
		game->keys.s = 0;
	if (keycode == 100)
		game->keys.d = 0;
	if (keycode == 65363)
		game->keys.left = 0;
	if (keycode == 65361)
		game->keys.right = 0;
	return (0);
}

int	close_game(t_game *game)
{
	if (!game)
		return (0);
	freepaths(game);
	freetab(game->model.map);
	freetab(game->model.fcontent);
	free_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}
