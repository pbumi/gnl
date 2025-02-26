/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:47:33 by pbumidan          #+#    #+#             */
/*   Updated: 2025/02/26 13:21:53 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*on_error(char **gnl, char **tmp)
{
	if (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	if (*gnl)
	{
		free(*gnl);
		*gnl = NULL;
	}
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

// char *get_next_line(int fd)
// {
//     static char *gnl = NULL;
//     int read_strlen;

//     if (!gnl)
//     {
//         gnl = malloc(1);
//         if (!gnl)
//             return (NULL);
//         gnl[0] = '\0';
//     }
//     if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &gnl, 0) < 0)
//         return (on_error(&gnl, &gnl));
//     read_strlen = gnl_call_read(fd, &gnl);
//     while (gnl_strchr(gnl, '\n') == 0 && read_strlen > 0)
//         read_strlen = gnl_call_read(fd, &gnl);
//     if (read_strlen < 0 || *gnl == '\0')
// 	{
//         return (on_error(&gnl, &gnl));
// 	}
// 	char *line = get_line(&gnl);
//     if (!line)
// 	{
//         return (NULL);
// 	}
//     return (line);
// }
