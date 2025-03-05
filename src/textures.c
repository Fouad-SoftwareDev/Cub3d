/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:19:31 by masmar            #+#    #+#             */
/*   Updated: 2025/02/26 12:34:41 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	load_textures(t_game *game)
{
	char	*paths[4];
	int		i;

	paths[0] = game->model.no;
	paths[1] = game->model.so;
	paths[2] = game->model.ea;
	paths[3] = game->model.we;
	i = 0;
	while (i < 4)
	{
		game->textures[i].img = mlx_xpm_file_to_image(
				game->mlx, paths[i],
				&game->textures[i].width,
				&game->textures[i].height);
		game->textures[i].addr = mlx_get_data_addr(
				game->textures[i].img,
				&game->textures[i].bpp,
				&game->textures[i].line_len,
				&game->textures[i].endian);
		if (!game->textures[i].img)
			close_game(game);
		i++;
	}
}
