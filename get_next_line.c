/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:36:07 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/08 10:47:02 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_included_new_line(char *accumulator, int bytes_read)
{
	int	i;

	if (bytes_read < BUFFER_SIZE)
		return (1);
	i = 0;
	if (!accumulator)
		return (0);
	while (accumulator[i])
	{
		if (accumulator[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	length_line_before_nl(char *accumulator)
{
	int	i;

	i = 0;
	while (accumulator[i])
	{
		if (accumulator[i] == '\n')
			return (i + 1);
		i++;
	}
	return (ft_strlen (accumulator));
}

char	*extract_line(char *accumulator)
{
	int		i;
	int		size_line;
	char	*line;

	size_line = length_line_before_nl(accumulator);
	line = ft_calloc(size_line + 1, sizeof(char));
	if (!line)
		return (NULL);
	line[size_line] = '\0';
	i = 0;
	while (i < size_line)
	{
		line[i] = accumulator[i];
		i++;
	}
	return (line);
}

char	*clean_accumulator(char *accumulator)
{
	int		i;
	int		size_line;
	char	*line;

	size_line = ft_strlen(accumulator) - length_line_before_nl(accumulator);
	if (size_line == 0)
	{
		free (accumulator);
		return (NULL);
	}
	line = ft_calloc(size_line + 1, sizeof(char));
	if (!line)
	{
		free (accumulator);
		return (NULL);
	}
	i = 0;
	while (i < size_line)
	{
		line[i] = accumulator[length_line_before_nl(accumulator) + i];
		i++;
	}
	free(accumulator);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*accumulator;
	char			buffer[BUFFER_SIZE + 1];
	char			*line;
	int				bytes_read;

	line = NULL;
	bytes_read = BUFFER_SIZE;
	buffer[bytes_read] = '\0';
	while (!is_included_new_line(accumulator, bytes_read))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0 && !accumulator)
		{
			free (accumulator);
			if (line)
				free (line);
			return (NULL);
		}
		accumulator = ft_strjoin(accumulator, buffer, bytes_read);
	}
	line = extract_line(accumulator);
	accumulator = clean_accumulator(accumulator);
	return (line);
}
