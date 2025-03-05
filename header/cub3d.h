/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:19:59 by fdahouk           #+#    #+#             */
/*   Updated: 2025/03/03 09:41:53 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"

# define MAX_MAP_HEIGHT	100
# define MAX_MAP_WIDTH	100
# define WIDTH	1280
# define HEIGHT	720
# define MINIMAP_SCALE	10

# define MINIMAP_VIEWPORT_SIZE 20
# define MINIMAP_CELL_SIZE 10
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200
# define OUT_OF_BOUNDS_COLOR 0x000000

typedef struct s_floor
{
	int	r;
	int	g;
	int	b;
}	t_floor;

typedef struct s_ceiling
{
	int	r;
	int	g;
	int	b;
}	t_ceiling;

typedef struct s_model
{
	int			maxwidth;
	int			maxheight;
	int			wtex;
	int			etex;
	int			stex;
	int			ntex;
	int			c;
	int			f;
	double		x;
	double		y;
	char		**map;
	char		**fcontent;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_ceiling	ceiling;
	t_floor		floor;
}	t_model;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
}	t_ray;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	t_model		model;
	t_img		textures[4];
	int			screen_width;
	int			screen_height;
	t_keys		keys;
	int			mouse_last_x;
}	t_game;

typedef struct s_linevars
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	x;
	int	y;
}	t_linevars;

typedef struct s_mmap
{
	double	cell_w;
	double	cell_h;
	int		off_x;
	int		off_y;
	int		map_w;
	int		map_h;
	double	vsx;
	double	vsy;
}	t_mmap;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/**** FREE: ****/
//	free.c:
void	freetab(char **line);
void	free_textures(t_game *game);
int		freepaths(t_game *game);

//	free2tab.c:
int		free_error(t_game *game);
void	free_game(t_game *game);
void	free2tab(char **fcontent, char **map);
void	ftt(char **map, char *trim);

/**** ERROR: ****/
//	error.c:
int		cerrorp(char *c);
void	error_exit(t_game *game, char *msg, char *path);

/**** MOVEMENT: ****/
//	move.c:
void	move_forward(t_game *game);
void	move_backward(t_game *game);

//	rotate.c:
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);

//	strafe.c:
void	strafe_left(t_game *game);
void	strafe_right(t_game *game);

/****  RAYCASTING: ****/
//	raycasting.c:
void	init_ray_params(t_game *game, t_ray *ray, int x);
void	set_step_and_side_dist(t_game *game, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	calc_line_placement(t_game *game, t_ray *ray);
void	pick_texture_num(t_ray *ray);

//	raycasting2.c:
void	setup_texture_coords(t_game *game, t_ray *ray);
void	draw_texture_column(t_game *game, t_ray *ray, int x);
void	draw_vertical_stripe(t_game *game, t_ray *ray, int x);
void	raycast(t_game *game);
void	draw_background(t_game *game);

/**** UTILS: ****/
//	atoi.c:
int		ft_atoi(const char *nptr);
char	*ft_strcpy(char *dest, char *src);
int		checkbeforeatoi(char *str);

//	check_map.c
int		checkborders(t_model *m);
int		checktopandbottomborder(t_model *m);
int		checkfirstcolborder(t_model *m);
int		checkoutterborder(t_model *m);

// ft_calloc.c:
void	*ft_calloc(size_t count, size_t size);

// ft_memcpy.c:
void	*ft_memcpy(void *dst, const void *src, size_t n);

//	ft_memset.c:
void	*ft_memset(void *b, int c, size_t len);

// ft_putstr_fd.c:
void	ft_putstr_fd(char *s, int fd);

// ft_strtrim.c:
char	*ft_strtrim(char *s1, char *set);

//	get_colors.c:
int		getsize(char **map);
int		getceilingrgb(char *s, t_model *m);
int		getfloorrgb(char *s, t_model *m);

//	get_textures.c:
int		getnotexture(char *s, t_model *m);
int		getsotexture(char *s, t_model *m);
int		getwstexture(char *s, t_model *m);
int		getestexture(char *s, t_model *m);

//	main_utils.c:
int		validate_arguments(int argc, char **argv);
int		check_file_exists(char *filename);
int		init_configuration(t_game *game, char *filename);
int		setup_game(t_game *game);
void	setup_hooks(t_game *game);

//	map_tools.c:
void	replace_whitespace_with_wall(char **map);
void	pad_map_rows(t_model *m);
void	maxwidth(t_model *m);

//	map_utils.c:
int		is_map_start(const char *line);
int		find_map_start(char **file);
int		count_map_lines(char **file, int start);
char	**copy_map(char **file, int start, int lines);
char	**extract_map(char **file, t_model *m);

//	raycasting_utils.c:
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		game_loop(t_game *game);
void	process_movement(t_game *game);

//	split.c:
char	**ft_split(char const *s, char c);

//	utils.c:
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		verify_file_extension(char *filename, char *ext);
int		checkidentifier(char *s, t_model *m);
void	exit_game(t_game *game);

//	utils2.c:
char	*ft_strdup(char *src);
int		ft_isalpha(int c);
int		is_whitespace(char c);
int		is_empty_line(const char *line);

/**** VALIDATION: ****/
//	validation.c:
int		inittexturesandcolors(t_model *m, char *filename);
int		convertcrgb(char **line, t_ceiling *c);
int		convertfrgb(char **line, t_floor *f);

//	validation2.c:
int		fillinfcontent(t_model *m, char *filename);
int		getlengthofile(char *filename);
int		checkmapvalidity(t_model *m);
int		check_map_character(char **map);
int		check_last_line_character(char **map);

//	validation3.c:
int		closeandreturn(int *fd);
int		is_invalid_surrounded(char **map);
int		check_map_pcount(char **map);

//	game_init.c:
void	initflags(t_model *mod);
int		init_game(t_game *game);
void	init_player(t_game *game);

//	input.c:
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		close_game(t_game *game);

//	main.c:
int		main(int argc, char **argv);

//	textures.c:
int		check_textures_exist(t_model *m);
void	load_textures(t_game *game);

/**** BONUS: ****/
//	mouse_movement.c:
void	rotate_player(t_game *game, double angle);
int		mouse_move(int x, int y, t_game *game);

//	minimap.c:
void	init_linevars(t_linevars *v, t_point start, t_point end);
void	draw_line(t_game *game, t_point start, t_point end, int color);
int		get_map_height(char **map);

//	minimap2.c:
void	draw_minimap_bg(t_game *game, t_mmap m);
void	draw_player_on_minimap(t_game *game, t_mmap m);
void	draw_minimap(t_game *game);

#endif