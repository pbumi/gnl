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

char	*gnl_calloc(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

t_link	*ft_lstlast(t_link *list)
{
	while (list != NULL)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

int	len_to_newline(t_link *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->buf[i] != '\0')
		{
			if (list->buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

int	trim_list(t_link **list)
{
	t_link	*last_node;
	t_link	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = gnl_calloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (0);
	clean_node = malloc(sizeof(t_link));
	if (clean_node == NULL)
		return (free(buf), 0);
	last_node = ft_lstlast(*list);
	i = 0;
	k = 0;
	while (last_node->buf[i] && last_node->buf[i] != '\n')
		++i;
	while (last_node->buf[i] && last_node->buf[++i])
		buf[k++] = last_node->buf[i];
	clean_node->buf = buf;
	clean_node->next = NULL;
	clean_and_free(list, clean_node, buf);
	return (1);
}

char	*clean_and_free(t_link **list, t_link *clean_node, char *buf)
{
	t_link	*temp;

	if (*list == NULL)
		return (NULL);
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (clean_node == 0 || buf == 0)
	{
		free(buf);
		return (NULL);
	}
	if (clean_node->buf[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
	return (NULL);
}