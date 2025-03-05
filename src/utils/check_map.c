/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:23:22 by masmar            #+#    #+#             */
/*   Updated: 2025/02/27 15:32:23 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	checkborders(t_model *m)
{
	if (checktopandbottomborder(m) == -1
		|| checkfirstcolborder(m) == -1 || checkoutterborder(m) == -1)
	{
		return (-1);
	}
	return (0);
}

int	checktopandbottomborder(t_model *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i][j])
	{
		if (m->map[i][j] != '1')
			return (-1);
		j++;
	}
	while (m->map[i])
		i++;
	i--;
	j = 0;
	while (m->map[i][j])
	{
		if (m->map[i][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

int	checkfirstcolborder(t_model *m)
{
	int	i;

	i = 0;
	while (m->map[i])
	{
		if (m->map[i][0] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	checkoutterborder(t_model *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = ft_strlen(m->map[i]) - 1;
		if (m->map[i][0] != '1' || m->map[i][j] != '1')
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
