/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:13:15 by noavetis          #+#    #+#             */
/*   Updated: 2025/02/13 17:03:48 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
int		get_next_line_utils(char buffer[BUFFER_SIZE + 1]);
char	*ft_strdup(const char *src);
char	*ft_alloc_end(const char *src ,int size);
size_t	ft_strlen(const char *str);

#endif