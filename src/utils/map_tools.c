/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:17 by masmar            #+#    #+#             */
/*   Updated: 2025/02/27 15:29:12 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	replace_whitespace_with_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_whitespace(map[i][j]))
			{
				map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}

void	pad_map_rows(t_model *m)
{
	int		y;
	char	*new_row;

	y = 0;
	while (y < m->maxheight)
	{
		if ((int)ft_strlen(m->map[y]) < m->maxwidth)
		{
			new_row = ft_calloc(m->maxwidth + 1, sizeof(char));
			ft_memset(new_row, '2', m->maxwidth);
			ft_memcpy(new_row, m->map[y], ft_strlen(m->map[y]));
			free(m->map[y]);
			m->map[y] = new_row;
		}
		y++;
	}
}

void	maxwidth(t_model *m)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	while (m->map[i])
	{
		if (ft_strlen(m->map[i]) > max)
			max = ft_strlen(m->map[i]);
		i++;
	}
	m->maxwidth = max;
}
