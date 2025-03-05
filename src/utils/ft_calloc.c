/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:40:05 by masmar            #+#    #+#             */
/*   Updated: 2025/02/25 12:37:36 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	s_zero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && size && count > (2147483648 / size))
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	s_zero(ptr, count * size);
	return (ptr);
}
