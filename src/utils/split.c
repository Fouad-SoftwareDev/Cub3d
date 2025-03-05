/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:54:17 by fdahouk           #+#    #+#             */
/*   Updated: 2025/02/19 20:28:22 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		if (str[i] != '\0')
			i++;
	}
	return (count);
}

static void	ft_strncpy(char *str, char const *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		str[i] = (char)src[i];
		i++;
	}
	str[i] = '\0';
}

static void	helper(char c, char const *s, char **strs, int *k)
{
	int	j;
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			strs[*k] = malloc((j + 1) * sizeof(char));
			ft_strncpy(strs[(*k)++], (char *)s + i, j);
			i += j;
		}
		else
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		k;

	strs = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	k = 0;
	if (strs == NULL)
		return (NULL);
	helper(c, s, strs, &k);
	strs[k] = NULL;
	return (strs);
}
