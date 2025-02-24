/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:12:55 by noavetis          #+#    #+#             */
/*   Updated: 2025/02/24 19:52:02 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check()
{
	

		


}

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
		if (check_n(ptr))
		{
			result = ft_strjoin(NULL, ptr, check_n(ptr), 0);
			ptr = ft_strjoin(ptr, ptr + check_n(ptr), ft_strlen(ptr + check_n(ptr)), 0);
			return (result);
		}
		result = ft_strjoin(ptr, ptr, ft_strlen(ptr), 0);
		ptr = NULL;
	}
	

	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size < 0)
		return (free(result), NULL);

	
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		if (check_n(buffer))
			result = ft_strjoin(result, buffer, check_n(buffer), 1);
		else
			result = ft_strjoin(result, buffer, ft_strlen(buffer), 1);
		if (read_size != BUFFER_SIZE)
		{
			if (check_n(buffer))
				ptr = ft_strjoin(NULL, buffer + check_n(buffer), ft_strlen(buffer + check_n(buffer)), 0);
			else
				ptr = ft_strjoin(NULL, buffer + ft_strlen(buffer), ft_strlen(buffer + ft_strlen(buffer)), 0);
			return (result);
		}
		if (read_size == BUFFER_SIZE && check_n(buffer))
		{
			ptr = ft_strjoin(NULL, buffer + check_n(buffer), ft_strlen(buffer + check_n(buffer)), 0);
			return (result);
		}
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}
