/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbumidan <pbumidan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:48:26 by pbumidan          #+#    #+#             */
/*   Updated: 2023/12/01 21:48:16 by pbumidan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy_n(char *dest, char *src, int x)
{

	x = 0;
	while (src [x])
	{
		dest[x] = src[x];
		x++;
	}
	dest [x] = '\0';
	return (dest);
}

int ft_check_n(char *str)
{
	int	x;

	if (!str)
		return (-1);
	x = 0;
	while (str[x] != '\0')
	{
		while (str[x] != '\n')
			x++;
		return (x);
	} 
	return (0);
}

