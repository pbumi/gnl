/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:47:23 by pbumidan          #+#    #+#             */
/*   Updated: 2025/01/06 19:10:44 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 10
// # endif

// # include <unistd.h>
// # include <stdlib.h>
// # include <fcntl.h>
// # include <string.h>

// char	*get_next_line(int fd);
// char	*get_end_line(int fd, char *source);
// char	*get_all_lines(int fd);
// char	*ft_free(char **ptr);
// int		ft_read_source(int fd, char **source);
// char	*gnl_strjoin(char const *s1, char const *s2);
// size_t	gnl_strlen(const char *s);
// char	*gnl_substr(char const *s, unsigned int start, size_t len);
// char	*gnl_strchr(const char *s, int c);

// #endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strchr(const char *s, int c);
void    cleanup_gnl(void);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#endif