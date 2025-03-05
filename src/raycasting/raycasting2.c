/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:18:46 by masmar            #+#    #+#             */
/*   Updated: 2025/03/03 10:49:53 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	setup_texture_coords(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = game->player.pos_y + ray->perp_wall_dist
			* ray->ray_dir_y;
	else
		ray->wall_x = game->player.pos_x + ray->perp_wall_dist
			* ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x
			* (double)game->textures[ray->tex_num].width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = game->textures[ray->tex_num].width - ray->tex_x - 1;
	ray->step = 1.0 * game->textures[ray->tex_num].height / ray->line_height;
	ray->tex_pos = (ray->draw_start - game->screen_height / 2
			+ ray->line_height / 2) * ray->step;
}

void	draw_texture_column(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	tex_y;
	int	color;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)ray->tex_pos
			& (game->textures[ray->tex_num].height - 1);
		color = *(int *)(game->textures[ray->tex_num].addr
				+ (tex_y * game->textures[ray->tex_num].line_len
					+ ray->tex_x * (game->textures[ray->tex_num].bpp / 8)));
		my_mlx_pixel_put(&game->img, x, y, color);
		ray->tex_pos += ray->step;
		y++;
	}
}

void	draw_vertical_stripe(t_game *game, t_ray *ray, int x)
{
	setup_texture_coords(game, ray);
	draw_texture_column(game, ray, x);
}

void	raycast(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < game->screen_width)
	{
		init_ray_params(game, &ray, x);
		set_step_and_side_dist(game, &ray);
		perform_dda(game, &ray);
		calc_line_placement(game, &ray);
		pick_texture_num(&ray);
		draw_vertical_stripe(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;
	int	ceil_color;
	int	floor_color;

	y = 0;
	ceil_color = (game->model.ceiling.r << 16)
		| (game->model.ceiling.g << 8)
		| (game->model.ceiling.b);
	floor_color = (game->model.floor.r << 16)
		| (game->model.floor.g << 8)
		| (game->model.floor.b);
	while (y < game->screen_height)
	{
		x = 0;
		while (x < game->screen_width)
		{
			if (y < game->screen_height / 2)
				my_mlx_pixel_put(&game->img, x, y, floor_color);
			else
				my_mlx_pixel_put(&game->img, x, y, ceil_color);
			x++;
		}
		y++;
	}
}
