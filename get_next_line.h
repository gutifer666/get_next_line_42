/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:26:52 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/12 16:52:17 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*add_to_accumulator(char *accumulator, char *buff);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
#endif