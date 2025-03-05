/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:43:28 by masmar            #+#    #+#             */
/*   Updated: 2025/02/27 16:33:13 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	closeandreturn(int *fd)
{
	close(*fd);
	return (-1);
}

int	is_invalid_surrounded(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' ||
				map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				if ((i > 0 && map[i - 1][j] == '2')
					|| (map[i + 1] && map[i + 1][j] == '2')
					|| (j > 0 && map[i][j - 1] == '2')
					|| (map[i][j + 1] && map[i][j + 1] == '2')
					|| (map[i + 1][j + 1] && map[i + 1][j + 1] == '2')
					|| (map[i - 1][j + 1] && map[i -1][j + 1] == '2'))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_pcount(char **map)
{
	int	pcount;
	int	i;
	int	j;

	pcount = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'W' || map[i][j] == 'E')
				pcount++;
			j++;
		}
		i++;
	}
	if (pcount != 1)
		return (cerrorp("Invalid player count!"));
	return (0);
}
