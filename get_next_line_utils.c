/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:15:43 by noavetis          #+#    #+#             */
/*   Updated: 2025/02/13 16:59:21 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (!str || !s1 || !s2)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *(s1++);
		i++;
	}
	while (*s2)
	{
		str[i] = *(s2++);
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	while (i < size + 1)
	{
		ptr[i] = src[i];
		i++;
	}
	return (ptr);
}

char	*ft_alloc_end(const char *src ,int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	while (i < size + 1)
	{
		ptr[i] = src[i];
		i++;
	}
	return (ptr);
}

int	get_next_line_utils(char buffer[BUFFER_SIZE + 1])
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
