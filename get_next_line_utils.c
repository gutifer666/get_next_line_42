/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:56:23 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/12 11:38:52 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

void	copy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*add_to_accumulator(char *accumulator, char *buff)
{
	size_t	size;
	size_t	size_accumulator;
	size_t	size_buff;
	char	*new_accumulator;

	if (accumulator == NULL)
	{
		accumulator = (char *)malloc(1);
		if (accumulator == NULL)
			return (NULL);
		*accumulator = '\0';
	}
	size_accumulator = ft_strlen(accumulator);
	size_buff = ft_strlen(buff);
	size = size_accumulator + size_buff;
	new_accumulator = (char *)malloc(size + 1);
	if (new_accumulator == NULL)
		return (NULL);
	copy(new_accumulator, accumulator, size_accumulator);
	copy(new_accumulator + size_accumulator, buff, size_buff);
	free (accumulator);
	return (new_accumulator);
}
