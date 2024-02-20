/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:47:33 by pbumidan          #+#    #+#             */
/*   Updated: 2023/12/16 17:24:03 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **str)
{
	free (*str);
	*str = NULL;
	return (NULL);
}

static char	*ft_free_all(char **source, char **str)
{
	free (*str);
	*source = NULL;
	return (NULL);
}

static char	*ft_get_line(char **source)
{
	int		x;
	char	*line;
	char	*old_source;
	char	*new_source;

	x = 0;
	old_source = *source;
	while (old_source[x] && old_source[x] != '\n')
	{
		x++;
	}
	line = ft_substr(old_source, 0, x + 1);
	if (!line)
	{
		return (ft_free_all(source, &old_source));
	}
	new_source = ft_substr(old_source, x + 1, ft_strlen(old_source));
	if (!new_source)
	{
		free (line);
		return (ft_free_all(source, &old_source));
	}
	free (old_source);
	*source = new_source;
	return (line);
}

static int	ft_read_source(int fd, char **source)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	temp = *source;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free (buffer);
		return (-1);
	}
	buffer[bytes_read] = '\0';
	*source = ft_strjoin(temp, buffer);
	if (!*source)
	{
		free (temp);
		free (buffer);
		return (-1);
	}
	free(temp);
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*source;
	int			bytes_read;

	if (!source)
	{
		source = (char *)malloc(sizeof(char));
		if (!source)
			return (NULL);
		source[0] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &source, 0) < 0)
	{
		return (ft_free(&source));
	}
	bytes_read = ft_read_source(fd, &source);
	while (ft_strchr(source, '\n') == 0 && bytes_read > 0)
	{
		bytes_read = ft_read_source(fd, &source);
	}
	if (bytes_read < 0 || *source == '\0')
	{
		return (ft_free(&source));
	}
	return (ft_get_line(&source));
}
