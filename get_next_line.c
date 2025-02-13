/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:12:55 by noavetis          #+#    #+#             */
/*   Updated: 2025/02/13 17:05:37 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*result;
	char	buffer[BUFFER_SIZE + 1];
	
	read(fd, buffer, BUFFER_SIZE);
	if (get_next_line_utils(buffer))
		return (ft_alloc_end(buffer, get_next_line_utils(buffer)));
	else
		result = ft_strdup(buffer);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		if (!get_next_line_utils(buffer))
			result = ft_strjoin(result, buffer);
		else
			return (ft_strjoin(result, ft_alloc_end(buffer, get_next_line_utils(buffer))));
	}
	return (result);
}