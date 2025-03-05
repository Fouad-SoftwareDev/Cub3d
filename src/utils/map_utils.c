/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdahouk <fdahouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:39:11 by fdahouk           #+#    #+#             */
/*   Updated: 2025/02/24 20:14:09 by fdahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	is_map_start(const char *line)
{
	int	j;
	int	has_valid_char;

	j = 0;
	has_valid_char = 0;
	while (line[j])
	{
		if (line[j] == '0' || line[j] == '1'
			|| line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'E' || line[j] == 'W')
			has_valid_char = 1;
		else if (!is_whitespace(line[j]))
			return (0);
		j++;
	}
	return (has_valid_char);
}

int	find_map_start(char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] && is_whitespace(file[i][j]))
			j++;
		if (file[i][j] == '\0')
		{
			i++;
			continue ;
		}
		if (is_map_start(file[i] + j))
			return (i);
		i++;
	}
	return (-1);
}

int	count_map_lines(char **file, int start)
{
	int	count;
	int	i;

	count = 0;
	i = start;
	while (file[i])
	{
		if (is_empty_line(file[i]))
		{
			i++;
			continue ;
		}
		count++;
		i++;
	}
	return (count);
}

char	**copy_map(char **file, int start, int lines)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	i = start;
	map = (char **)malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (j < lines)
	{
		if (!is_empty_line(file[i]))
			map[j++] = ft_strdup(file[i]);
		i++;
	}
	map[j] = NULL;
	return (map);
}

char	**extract_map(char **file, t_model *m)
{
	int	mapstart;
	int	map_lines;

	mapstart = find_map_start(file);
	if (mapstart == -1)
	{
		return (NULL);
	}
	map_lines = count_map_lines(file, mapstart);
	if (map_lines <= 0)
	{
		return (NULL);
	}
	m->maxheight = map_lines;
	return (copy_map(file, mapstart, map_lines));
}
