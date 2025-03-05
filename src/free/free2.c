/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:04:20 by masmar            #+#    #+#             */
/*   Updated: 2025/02/28 12:33:53 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	free_error(t_game *game)
{
	freepaths(game);
	freetab(game->model.map);
	freetab(game->model.fcontent);
	return (-1);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	while (i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free2tab(char **fcontent, char **map)
{
	freetab(fcontent);
	freetab(map);
}

void	ftt(char **map, char *trim)
{
	freetab(map);
	free(trim);
}
