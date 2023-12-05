/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:03:41 by pbumidan          #+#    #+#             */
/*   Updated: 2023/12/05 19:42:28 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h> 

static char	*ft_extractsource(int fd, char *source)
{
	int		x_read;
	char	*buffer;

	x_read = 0;
	if (source == NULL && x_read == 0)
	{
		source = (char *)malloc(sizeof(char) * 1);
		if (!source)
			return (NULL);
		source[0] = '\0';
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr_n(source) == 0)
	{
		x_read = read(fd, buffer, BUFFER_SIZE);
		if (read < 0)
		{
			free (buffer);
			free (source);
			return (NULL);
		}
		buffer[x_read] = '\0';
		source = ft_strjoin(source, buffer);
		if (source[0] == '\0')
		{
			free (source);
			free (buffer);
			return (NULL);
		}
		if (x_read == 0)
		{
			break ;
		}
	}
	free(buffer);
	return (source);
}

static char	*ft_extractline(char *temp, char **source)
{
	char	*line;
	int		x;

	x = 0;
	while (temp[x] != '\0' && temp[x] != '\n')
		x++;
	line = ft_substr(temp, 0, x + 1);
	if (!line)
	{
		return (NULL);
	}
	*source = ft_substr(temp, x + 1, ft_strlen(temp));
	if (!source)
	{
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	*source;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_extractsource(fd, source);
	if (temp == NULL)
		return (NULL);
	line = ft_extractline(temp, &source);
	if (line == NULL)
		return (NULL);
	return (line);
}
