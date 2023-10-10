/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastane <ecastane@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:26:53 by ecastane          #+#    #+#             */
/*   Updated: 2023/10/07 20:36:14 by ecastane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_read(int fd, char *buffer);
char	*ft_get_line(char *buffer);
char	*ft_save(char *buffer);
char	*get_next_line(int fd);
char	*ft_free(char **str);

size_t	ft_strlen(const char *s);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif