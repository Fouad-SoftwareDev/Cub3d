/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:36:46 by fdahouk           #+#    #+#             */
/*   Updated: 2025/03/01 01:13:35 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	print_help(void)
{
	ft_putstr_fd("Controls:\n", 1);
	ft_putstr_fd("  W: Move Forward\n", 1);
	ft_putstr_fd("  S: Move Backward\n", 1);
	ft_putstr_fd("  A: Strafe Left\n", 1);
	ft_putstr_fd("  D: Strafe Right\n", 1);
	ft_putstr_fd("  Left Arrow: Rotate Left\n", 1);
	ft_putstr_fd("  Right Arrow: Rotate Right\n", 1);
	ft_putstr_fd("  ESC: Exit Game\n", 1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game.keys, 0, sizeof(game.keys));
	if (validate_arguments(argc, argv) != 0)
		return (-1);
	if (check_file_exists(argv[1]) != 0)
		return (-1);
	if (init_configuration(&game, argv[1]) != 0)
		return (-1);
	if (setup_game(&game) != 0)
		return (-1);
	setup_hooks(&game);
	print_help();
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
