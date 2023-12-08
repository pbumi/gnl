/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:48:26 by pbumidan          #+#    #+#             */
/*   Updated: 2023/12/08 16:08:30 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	if (len > (slen - start))
		len = (slen - start);
	substr = (char *)malloc((sizeof(char)) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	x;
	size_t	y;
	size_t	len;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len) + 1);
	if (!str)
	{
		return (NULL);
	}
	x = -1;
	while (s1[++x])
	{
		str[x] = s1[x];
	}
	free (s1);
	y = -1;
	while (s2[++y])
	{
		str[x + y] = s2[y];
	}
	str[len] = '\0';
	return (str);
}

int	ft_strchr_n(char *s)
{
	size_t	x;

	if (s == NULL)
		return (-1);
	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == '\n')
		{
			return (1);
		}
		x++;
	}
	return (0);
}
