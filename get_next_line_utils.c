/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:15:43 by noavetis          #+#    #+#             */
/*   Updated: 2025/02/23 01:05:51 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, const char *s2, int flag, int join)
{
	char	*str;
	size_t	size;
	size_t	i;
	
	size = 0;
	if (join && s1 && s2)
		size = strlen_check(s1, 0) + strlen_check(s2, flag);
	else if (s2)
		size = strlen_check(s2, flag);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	i = 0;
	while (join && s1 && s1[i] && i < size)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && *s2 && i < size)
		str[i++] = *(s2++);
	if (i == 0)
	{
		free(str);
		return (free(s1), NULL);
	}
	str[i] = '\0';
	return (free(s1), str);
}

size_t	strlen_check(const char *buffer, int flag)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (flag && buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	if (flag)
		return (i + 1);
	return (i);
}
