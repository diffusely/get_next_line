/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:12:55 by noavetis          #+#    #+#             */
/*   Updated: 2025/02/23 00:59:06 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*ptr = NULL;
	ssize_t			read_size;
	char			buffer[BUFFER_SIZE + 1];
	char			*result;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	result = NULL;
	if (ptr)
	{
		result = ft_strjoin(NULL, ptr, 1, 0);
		ptr = ft_strjoin(ptr , ptr + strlen_check(ptr, 1), 1, 0);
	}
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size)
	{
		if (read_size != BUFFER_SIZE)
			buffer[read_size] = '\0';
		result = ft_strjoin(result, buffer, 1, 1);
		if (read_size != BUFFER_SIZE)
		{
			ptr = ft_strjoin(NULL, buffer + strlen_check(buffer, 1), 0, 0);
			return (result);
		}
		if (read_size == BUFFER_SIZE && strlen_check(buffer, 1) - 1 != BUFFER_SIZE)
		{
			ptr = ft_strjoin(NULL, buffer + strlen_check(buffer, 1), 1, 0);
			return (result);
		}
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}