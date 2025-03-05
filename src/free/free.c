/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:31:10 by masmar            #+#    #+#             */
/*   Updated: 2025/02/26 14:06:28 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	freetab(char **line)
{
	int	i;

	if (line == NULL)
		return ;
	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img)
		{
			mlx_destroy_image(game->mlx, game->textures[i].img);
		}
		i++;
	}
}

int	freepaths(t_game *game)
{
	if (game->model.so)
		free(game->model.so);
	if (game->model.ea)
		free(game->model.ea);
	if (game->model.we)
		free(game->model.we);
	if (game->model.no)
		free(game->model.no);
	return (-1);
}
