/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:41:48 by fdahouk           #+#    #+#             */
/*   Updated: 2025/02/28 12:34:54 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	ft_atoi(const char *nptr)
{
	int	count;
	int	sign;
	int	i;
	int	res;

	res = 0;
	count = 0;
	i = 0;
	sign = 1;
	while (nptr[i] != '\0' && (nptr[i] == ' '
			|| (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	while (nptr[i] != '\0' && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		count++;
		if (count == 2)
			return (res);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10 + (nptr[i++] - '0');
	return (res * sign);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*odest;

	odest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (odest);
}

int	checkbeforeatoi(char *str)
{
	int		i;
	char	*new;

	if (!str)
		return (-1);
	i = 0;
	new = ft_strtrim(str, " \n\t");
	while (new[i] && (new[i] == ' ' || new[i] == '\t' || new[i] == '\n'))
		i++;
	while (new[i])
	{
		if ((new[i] == ' ' || new[i] == '\t'
				|| new[i] == '\n') && new[i + 1] == '\0')
			break ;
		else if ((new[i] < '0' || new[i] > '9'))
			return (free(new), -1);
		i++;
	}
	free(new);
	return (1);
}
