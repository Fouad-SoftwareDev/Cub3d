/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:28:32 by masmar            #+#    #+#             */
/*   Updated: 2025/02/27 16:31:25 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (i < n - 1) && s1[i] != '\0')
		i++;
	if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

int	verify_file_extension(char *filename, char *ext)
{
	size_t	len_filename;
	size_t	len_ext;

	len_filename = ft_strlen(filename);
	len_ext = ft_strlen(ext);
	if (len_filename < len_ext
		|| ft_strncmp(filename + len_filename - len_ext, ext, len_ext) != 0)
		return (-1);
	return (0);
}

int	checkidentifier(char *s, t_model *m)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		return (0);
	if ((s[i] == 'N' && s[i + 1] == 'O') && (s[i + 1]))
		return (getnotexture(s + i, m));
	else if ((s[i] == 'S' && s[i + 1] == 'O') && (s[i + 1]))
		return (getsotexture(s + i, m));
	else if ((s[i] == 'E' && s[i + 1] == 'A') && (s[i + 1]))
		return (getestexture(s + i, m));
	else if ((s[i] == 'W' && s[i + 1] == 'E') && (s[i + 1]))
		return (getwstexture(s + i, m));
	else if (s[i] == 'C')
		return (getceilingrgb(s + i, m));
	else if (s[i] == 'F')
		return (getfloorrgb(s + i, m));
	else if (!(s[i] == '0' || s[i] == '1' || s[i] == 'N'
			|| s[i] == 'S' || s[i] == 'W' || s[i] == 'E'))
		return (cerrorp("Invalid Identifier"));
	return (0);
}

void	exit_game(t_game *game)
{
	mlx_mouse_show(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
