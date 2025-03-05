/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:02:43 by masmar            #+#    #+#             */
/*   Updated: 2025/02/21 22:40:29 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

char	*ft_strdup(char *src)
{
	size_t	l;
	char	*s;
	int		i;

	l = ft_strlen(src);
	if (l > 0 && src[l - 1] == '\n')
		l--;
	s = (char *)malloc(l + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < (int)l)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' );
}

int	is_empty_line(const char *line)
{
	while (*line)
	{
		if (!is_whitespace(*line))
			return (0);
		line++;
	}
	return (1);
}
