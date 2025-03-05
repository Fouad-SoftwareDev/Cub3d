/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:39:58 by masmar            #+#    #+#             */
/*   Updated: 2025/02/22 01:39:58 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	fillinfcontent(t_model *m, char *filename)
{
	char	*s;
	int		fd;
	int		size;
	int		i;

	i = 0;
	size = getlengthofile(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (cerrorp("Could Not Open File!"));
	s = get_next_line(fd);
	m->fcontent = (char **)malloc(sizeof(char *) * (size +1));
	if (!m->fcontent)
		return (cerrorp("Malloc Failed"));
	m->fcontent[i] = s;
	while (s != NULL)
	{
		s = get_next_line(fd);
		i++;
		m->fcontent[i] = s;
	}
	m->fcontent[i] = NULL;
	close(fd);
	return (0);
}

int	getlengthofile(char *filename)
{
	char	*s;
	int		count;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (cerrorp("Could Not Open File!"));
	count = 0;
	s = get_next_line(fd);
	while (s != NULL)
	{
		free(s);
		count++;
		s = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	checkmapvalidity(t_model *m)
{
	if (m->c != 1 || m->f != 1
		|| m->ntex != 1 || m->stex != 1 || m->wtex != 1 || m->etex != 1)
		return (freetab(m->fcontent), cerrorp("Missing Config"));
	m->map = extract_map(m->fcontent, m);
	if (!m->map)
	{
		freetab(m->fcontent);
		return (cerrorp("Invalid Map"));
	}
	replace_whitespace_with_wall(m->map);
	if (check_last_line_character(m->map) == -1
		|| check_map_character(m->map) == -1 || check_map_pcount(m->map) == -1)
	{
		free2tab(m->fcontent, m->map);
		return (-1);
	}
	if (checkborders(m) == -1)
		return (free2tab(m->fcontent, m->map), cerrorp("Invalid Borders!"));
	maxwidth(m);
	pad_map_rows(m);
	if (is_invalid_surrounded(m->map) == -1)
		return (free2tab(m->fcontent, m->map),
			cerrorp("Map Not Surrounded By Walls!"));
	return (0);
}

int	check_last_line_character(char **map)
{
	int	j;
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '0' && map[i][j] != '1'
			&& map[i][j] != 'N' && map[i][j] != 'S'
			&& map[i][j] != 'W' && map[i][j] != 'E'
			&& map[i][j] != '\n')
			return (cerrorp("Map is not at EOF!"));
		j++;
	}
	return (0);
}

int	check_map_character(char **map)
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
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'W' && map[i][j] != 'E'
				&& map[i][j] != '\n')
				return (cerrorp
					("Invalid Characters or Map Is Not At EOF!"));
			j++;
		}
		i++;
	}
	return (0);
}
