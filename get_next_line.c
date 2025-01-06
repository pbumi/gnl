/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:47:33 by pbumidan          #+#    #+#             */
/*   Updated: 2025/01/06 18:49:44 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// char *ft_free(char **str)
// {
//     if (str && *str)
//     {
//         free(*str);  // Free memory pointed by *str
//         *str = NULL; // Set the pointer to NULL to avoid dangling pointers
//     }
//     return (NULL); // Return NULL to set the calling pointer to NULL
// }
// // char	*ft_free(char **str)
// // {
// // 	free (*str);
// // 	*str = NULL;
// // 	return (NULL);
// // }

// static char *ft_free_all(char **source, char **str)
// {
//     if (str && *str)
//     {
//         free(*str);  // Free memory pointed by *str
//         *str = NULL; // Set the pointer to NULL
//     }
//     if (source && *source)
//     {
//         *source = NULL; // Set source to NULL explicitly
//     }
//     return (NULL); // Return NULL to indicate both have been cleared
// }
// // static char	*ft_free_all(char **source, char **str)
// // {
// // 	free (*str);
// // 	*source = NULL;
// // 	return (NULL);
// // }

// static char	*ft_get_line(char **source)
// {
// 	int		x;
// 	char	*line;
// 	char	*old_source;
// 	char	*new_source;

// 	x = 0;
// 	old_source = *source;
// 	while (old_source[x] && old_source[x] != '\n')
// 	{
// 		x++;
// 	}
// 	line = gnl_substr(old_source, 0, x + 1);
// 	if (!line)
// 	{
// 		return (ft_free_all(source, &old_source));
// 	}
// 	new_source = gnl_substr(old_source, x + 1, gnl_strlen(old_source));
// 	if (!new_source)
// 	{
// 		free (line);
// 		return (ft_free_all(source, &old_source));
// 	}
// 	free (old_source);
// 	*source = new_source;
// 	return (line);
// }

// int	ft_read_source(int fd, char **source)
// {
// 	char	*buffer;
// 	char	*temp;
// 	int		bytes_read;

// 	temp = *source;
// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (-1);
// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	if (bytes_read < 0)
// 	{
// 		free (buffer);
// 		return (-1);
// 	}
// 	buffer[bytes_read] = '\0';
// 	*source = gnl_strjoin(temp, buffer);
// 	if (!*source)
// 	{
// 		free (temp);
// 		free (buffer);
// 		return (-1);
// 	}
// 	free(temp);
// 	free(buffer);
// 	return (bytes_read);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*source = NULL;
// 	int			bytes_read;

// 	if (fd < 0) // Special case to manually free static memory
// 	{
// 		ft_free(&source);  // Free and set to NULL
// 		return (NULL);
// 	}
// 	if (!source)
// 	{
// 		source = (char *)malloc(sizeof(char));
// 		if (!source)
// 			return (NULL);
// 		source[0] = '\0';
// 	}
// 	if (BUFFER_SIZE <= 0 || read(fd, &source, 0) < 0)
// 		return (ft_free(&source));
// 	bytes_read = ft_read_source(fd, &source);
// 	while (gnl_strchr(source, '\n') == 0 && bytes_read > 0)
// 		bytes_read = ft_read_source(fd, &source);
// 	if (bytes_read < 0 || *source == '\0')
// 	{
// 		return (ft_free(&source));
// 	}
// 	return (ft_get_line(&source));
// }
#include "get_next_line.h"

static char	*on_error(char **gnl, char **tmp)
{
	free (*tmp);
	*gnl = 0;
	return (NULL);
}

static char	*get_line(char **gnl)
{
	int		i;
	char	*the_line;
	char	*tmp;
	char	*new;

	i = 0;
	tmp = *gnl;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	the_line = gnl_substr(tmp, 0, i);
	if (!the_line)
		return (on_error(gnl, &tmp));
	new = gnl_substr(tmp, i, gnl_strlen(tmp) - i);
	if (!new)
	{
		free (the_line);
		return (on_error(gnl, &tmp));
	}
	free (tmp);
	*gnl = new;
	return (the_line);
}

static int	gnl_call_read(int fd, char **gnl)
{
	char	*buf;
	char	*temp;
	int		read_strlen;

	temp = *gnl;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	read_strlen = read(fd, buf, BUFFER_SIZE);
	if (read_strlen < 0)
	{
		free (buf);
		return (-1);
	}
	buf[read_strlen] = '\0';
	*gnl = gnl_strjoin(temp, buf);
	if (!*gnl)
	{
		free (temp);
		free (buf);
		return (-1);
	}
	free(temp);
	free(buf);
	return (read_strlen);
}

char	*get_next_line(int fd)
{
	static char	*gnl;
	int			read_strlen;

	if (!gnl)
	{
		gnl = malloc(1);
		if (!gnl)
			return (NULL);
		gnl[0] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &gnl, 0) < 0)
		return (on_error(&gnl, &gnl));
	read_strlen = gnl_call_read(fd, &gnl);
	while (gnl_strchr(gnl, '\n') == 0 && read_strlen > 0)
		read_strlen = gnl_call_read(fd, &gnl);
	if (read_strlen < 0 || *gnl == '\0')
		return (on_error(&gnl, &gnl));
	return (get_line(&gnl));
}