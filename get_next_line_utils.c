/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:48:26 by pbumidan          #+#    #+#             */
/*   Updated: 2023/11/30 21:50:31 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	size_t	x;

	x = 0;
	while (src [x])
	{
		dest[x] = src[x];
		x++;
	}
	dest [x] = '\0';
	return (dest);
}
