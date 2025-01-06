// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line_utils.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: pbumidan <pbumidan@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/12/15 14:47:47 by pbumidan          #+#    #+#             */
// /*   Updated: 2025/01/06 18:08:14 by pbumidan         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// size_t	gnl_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != 0)
// 		i++;
// 	return (i);
// }

// char	*gnl_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	slen;
// 	size_t	i;

// 	if (len == 0 || s == NULL)
// 		return (NULL);
// 	slen = gnl_strlen(s);
// 	if (start >= slen)
// 		len = 0;
// 	if (len > (slen - start))
// 		len = (slen - start);
// 	substr = calloc(len + 1, sizeof(char)); //malloc((sizeof(char)) * (len + 1));
// 	if (!substr)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		substr[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	substr[i] = '\0';
// 	return (substr);
// }

// char	*gnl_strchr(const char *s, int c)
// {
// 	size_t	i;
// 	size_t	slen;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	slen = gnl_strlen(s);
// 	while (i < slen)
// 	{
// 		if (s[i] == (char)c)
// 		{
// 			return ((char *)s + i);
// 		}
// 			//return (&((char *)s)[i]);
// 		i++;
// 	}
// 	return (0);
// }

// char	*gnl_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	a;
// 	size_t	b;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	str = ((char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1)));
// 	if (str == NULL)
// 		return (NULL);
// 	a = 0;
// 	while (s1[a])
// 	{
// 		str[a] = s1[a];
// 		a++;
// 	}
// 	b = 0;
// 	while (s2[b])
// 	{
// 		str[a] = s2[b];
// 		a++;
// 		b++;
// 	}
// 	str[a] = '\0';
// 	return (str);
// }

#include "get_next_line.h"

static void	*gnl_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	n;

	n = len;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[n -1] = ((unsigned char *)src)[n -1];
			n--;
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	flen;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	flen = gnl_strlen(s1) + gnl_strlen(s2);
	ptr = calloc(flen + 1, sizeof(char));
	if (!ptr)
		return (0);
	gnl_memmove(ptr, s1, gnl_strlen(s1));
	gnl_memmove(ptr + gnl_strlen(s1), s2, gnl_strlen(s2));
	ptr[flen] = '\0';
	return (ptr);
}

char *gnl_substr(char *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i = 0;

    if (!s)
        return (NULL);

    substr = (char *)calloc(len + 1, sizeof(char)); // Allocate memory for the substring
    if (!substr)
        return (NULL);

    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';  // Null terminate the substring
    return (substr);
}

// char	*gnl_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*ptr;
// 	size_t	slen;

// 	if (!s)
// 		return (NULL);
// 	slen = gnl_strlen(s);
// 	if ((size_t)start >= slen)
// 		len = 0;
// 	if (slen - (size_t)start < len)
// 		len = slen - (size_t)start;
// 	ptr = calloc((len + 1), sizeof(char));
// 	if (ptr == NULL)
// 		return (NULL);
// 	gnl_memmove(ptr, &s[start], len);
// 	ptr[len] = '\0';
// 	return (ptr);
// }

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;
	size_t	slen;

	i = 0;
	if (!s)
		return (0);
	slen = gnl_strlen(s);
	while (i < slen +1)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}