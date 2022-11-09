/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:56:23 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/09 10:21:44 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(int count, int size)
{
	char	*ptr;
	int		i;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	i = 0;
	while (i < count * size)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_strjoin(char *accumulator, char *buffer, int n)
{
	char	*added;
	int		len;
	int		i;

	if (!accumulator)
	{
		accumulator = ft_calloc(1, 1);
		if (!accumulator)
			return (NULL);
	}
	len = ft_strlen(accumulator) + n;
	added = ft_calloc(len + 1, sizeof(char));
	if (!added)
	{
		free (accumulator);
		return (NULL);
	}
	i = -1;
	while (accumulator[++i])
		added[i] = accumulator [i];
	len = -1;
	while (++len < n)
		added[len + i] = buffer[len];
	free (accumulator);
	return (added);
}
