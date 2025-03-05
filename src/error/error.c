/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:12:20 by masmar            #+#    #+#             */
/*   Updated: 2025/02/27 15:08:55 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	cerrorp(char *c)
{
	printf("%s\n", c);
	return (-1);
}

void	error_exit(t_game *game, char *msg, char *path)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
