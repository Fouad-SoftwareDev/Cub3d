/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:58:15 by masmar            #+#    #+#             */
/*   Updated: 2025/03/03 10:48:59 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	init_linevars(t_linevars *v, t_point start, t_point end)
{
	v->x = start.x;
	v->y = start.y;
	v->dx = end.x - start.x;
	if (v->dx < 0)
		v->dx = -v->dx;
	v->dy = end.y - start.y;
	if (v->dy < 0)
		v->dy = -v->dy;
	if (start.x < end.x)
		v->sx = 1;
	else
		v->sx = -1;
	if (start.y < end.y)
		v->sy = 1;
	else
		v->sy = -1;
	v->err = v->dx - v->dy;
}

void	draw_line(t_game *game, t_point start, t_point end, int color)
{
	t_linevars	v;

	init_linevars(&v, start, end);
	while (1)
	{
		my_mlx_pixel_put(&game->img, v.x, v.y, color);
		if (v.x == end.x && v.y == end.y)
			break ;
		v.e2 = v.err * 2;
		if (v.e2 > -v.dy)
		{
			v.err -= v.dy;
			v.x += v.sx;
		}
		if (v.e2 < v.dx)
		{
			v.err += v.dx;
			v.y += v.sy;
		}
	}
}

int	get_map_height(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}
