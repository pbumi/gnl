/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:47:33 by pbumidan          #+#    #+#             */
/*   Updated: 2025/01/06 18:27:26 by pbumidan         ###   ########.fr       */
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

static int	found_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf[i] && i < BUFFER_SIZE)
		{
			if (list->buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

static void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->buf[i] != '\0')
		{
			if (list->buf[i] == '\n')
			{
				str[k] = '\n';
				str[k + 1] = '\0';
				return ;
			}
			str[k++] = list->buf[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

static int	add_to_list(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (0);
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->buf = buf;
	new_node->next = NULL;
	return (1);
}

static int	create_list(t_list **list, int fd)
{
	int		bytes_read;
	char	*buf;

	bytes_read = 0;
	while (!found_newline(*list))
	{
		buf = ft_calloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (0);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			free(buf);
			return (1);
		}
		if (!(add_to_list(list, buf)) || bytes_read < 0)
		{
			free(buf);
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;
	int				str_len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (clean_and_free(&list, 0, line));
	if (!(create_list(&list, fd)))
		return (clean_and_free(&list, 0, line));
	if (list == NULL)
		return (NULL);
	str_len = len_to_newline(list);
	line = ft_calloc(str_len + 1);
	if (line == NULL)
		return (clean_and_free(&list, 0, line));
	copy_str(list, line);
	if (!(trim_list(&list)))
		return (clean_and_free(&list, 0, line));
	return (line);
}