/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:03:41 by pbumidan          #+#    #+#             */
/*   Updated: 2023/12/01 21:48:14 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// static char	*ft_extractsource(int fd, char *source)
// {
// 	int		index;
// 	char	*buffer;

// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
// 	if (!buffer)
// 		return (NULL);
// 	index = 1;
// 	while (index > 0)
// 	{
// 		index = read(fd, buffer, BUFFER_SIZE);
// 		buffer[index] = '\0';
// 	}
// 	printf("1 %s", source);
// 	return (source);
// }

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
	int		x_read;
	char	*buffer;
	char	*source;
	char	*line;
	int		index;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);

	x_read = read(fd, buffer, BUFFER_SIZE);
	buffer[x_read] = '\0';

	source = buffer;
	index = ft_check_n(source);
	line = NULL;
	printf("1 %s", buffer);
//	while (index > 0)
//		return (ft_strcpy_n(line, source, index));
//	if (index == 0)
//		return (NULL);
//	else
		return (source);
}
