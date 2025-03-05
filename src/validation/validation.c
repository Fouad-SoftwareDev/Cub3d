/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:35:44 by masmar            #+#    #+#             */
/*   Updated: 2025/02/27 16:30:38 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	inittexturesandcolors(t_model *m, char *filename)
{
	char	*s;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (cerrorp("Invalid file!"));
	if (verify_file_extension(filename, ".cub") == -1)
	{
		close(fd);
		return (cerrorp("Invalid File Extension!"));
	}
	s = get_next_line(fd);
	while (s != NULL)
	{
		if (checkidentifier(s, m) == -1)
		{
			free(s);
			close(fd);
			return (-1);
		}
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	convertcrgb(char **line, t_ceiling *c)
{
	if (line[3])
		return (-1);
	if (line[0] && line[1] && line[2]
		&& checkbeforeatoi(line[0]) == 1 && checkbeforeatoi(line[1]) == 1
		&& checkbeforeatoi(line[2]) == 1)
	{
		c->g = ft_atoi(line[1]);
		c->r = ft_atoi(line[0]);
		c->b = ft_atoi(line[2]);
		if ((c->r >= 0 && c->g >= 0 && c->b >= 0)
			&& (c->r <= 255 && c->g <= 255 && c->b <= 255))
			return (0);
	}
	return (-1);
}

int	convertfrgb(char **line, t_floor *f)
{
	if (line[3])
		return (-1);
	if (line[0] && line[1] && line[2]
		&& checkbeforeatoi(line[0]) == 1 && checkbeforeatoi(line[1]) == 1
		&& checkbeforeatoi(line[2]) == 1)
	{
		f->r = ft_atoi(line[0]);
		f->g = ft_atoi(line[1]);
		f->b = ft_atoi(line[2]);
		if ((f->r >= 0 && f->g >= 0 && f->b >= 0)
			&& (f->r <= 255 && f->g <= 255 && f->b <= 255))
			return (0);
	}
	return (-1);
}
