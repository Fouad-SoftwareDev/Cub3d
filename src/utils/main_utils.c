/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:06:21 by masmar            #+#    #+#             */
/*   Updated: 2025/03/03 10:50:33 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	validate_arguments(int argc, char **argv)
{
	if (argc != 2)
		return (cerrorp("Usage: ./cub3d <map.cub>"));
	if (verify_file_extension(argv[1], ".cub") == -1)
		return (cerrorp
			("Invalid Extension: Only .cub Files Are Acceptable."));
	return (0);
}

int	check_file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (cerrorp("Invalid File!"));
	close(fd);
	return (0);
}

int	init_configuration(t_game *game, char *filename)
{
	initflags(&game->model);
	if (inittexturesandcolors(&game->model, filename) != 1)
		return (freepaths(game));
	fillinfcontent(&game->model, filename);
	if (checkmapvalidity(&game->model) == -1)
		return (freepaths(game));
	return (0);
}

int	setup_game(t_game *game)
{
	if (!init_game(game))
		return (cerrorp("Game Initialization Failed"));
	init_player(game);
	load_textures(game);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, &game_loop, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	mlx_hook(game->win, 17, 0, &close_game, game);
}
