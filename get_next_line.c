/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:03:41 by pbumidan          #+#    #+#             */
/*   Updated: 2023/11/30 22:27:28 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_extractsource(int fd, char *source)
{
	int		index;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);
	index = 1;
	while (index > 0)
	{
		index = read(fd, buffer, BUFFER_SIZE);
		buffer[index] = '\0';
	}
	printf("1 %s", source);
	return (source);
}

// static char	*ft_extractline(char *source)
// {
// 	char	*line;
// 	size_t	len;
// 	int		x;

// 	x = 0;
// 	while (source[x] != '\0' && source[x] != '\n')
// 		x++;
// 	len = x + (source[x] == '\n');
// 	line = (char *)malloc(sizeof(char) * (len) + 1);
// 	if (!line)
// 		return (NULL);
// 	ft_strcpy(line, source);
// 	return (line);
// }

char	*get_next_line(int fd)
{
	//char		*line;
	static char	*source;

	source = ft_extractsource(fd, source);
//	line = ft_extractline(source);
	//return (line);
	//line = source;
	printf("2 %s", source);
	return (source);
}
