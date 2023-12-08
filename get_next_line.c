/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:03:41 by pbumidan          #+#    #+#             */
/*   Updated: 2023/12/08 16:18:06 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h> 

static char	*ft_extractsource(int fd, char *source)
{
	int		x_read;
	char	*buffer;

	x_read = 1;
	if (source == NULL)
	{
		source = (char *)malloc(sizeof(char) * 1);
		if (source == NULL)
			return (NULL);
		source[0] = '\0';
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buffer == NULL)
		return (NULL);
	while (ft_strchr_n(source) == 0 && x_read > 0)
	{
		x_read = read(fd, buffer, BUFFER_SIZE);
		if (x_read == -1)
		{
			free (buffer);
			free (source);
			return (NULL);
		}
		if (x_read > 0)
		{
			buffer[x_read] = '\0';
			source = ft_strjoin(source, buffer);
		}
	}
	free(buffer);
	return (source);
}

static char	*ft_extractline(char *temp, char **source)
{
	char	*line;
	int		x;

	if (temp[0] == '\0')
	{
		free (temp);
		return (NULL);
	}
	x = 0;
	while (temp[x] != '\0' && temp[x] != '\n')
		x++;
	line = ft_substr(temp, 0, x + 1);
	if (!line)
	{
		free (temp);
		return (NULL);
	}
	*source = ft_substr(temp, x + 1, ft_strlen(temp));
	if (!source)
	{
		return (NULL);
	}
	free (temp);
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
	{
	//	free (temp);
		return (NULL);
	}
	line = ft_extractline(temp, &source);
	if (line == NULL)
	{
		return (NULL);
	}
	if (source[0] == '\0')
	{
		free (source);
		source = NULL;
	}
	return (line);
}
