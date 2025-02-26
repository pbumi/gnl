/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:47:23 by pbumidan          #+#    #+#             */
/*   Updated: 2025/02/26 13:21:36 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strchr(const char *s, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#endif