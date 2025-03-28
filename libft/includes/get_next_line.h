/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:40:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/18 15:17:41 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		gnl_ft_strchr(const char *s, int c);
void	gnl_ft_strlcpy(char *dst, const char *src, size_t size);
size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strjoin(char const *s1, char const *s2);

#endif
