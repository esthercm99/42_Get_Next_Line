/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastane <ecastane@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:26:53 by ecastane          #+#    #+#             */
/*   Updated: 2023/10/07 00:15:43 by ecastane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_read(int fd, char *save);
char	*ft_get_line(char *save);
char	*ft_save(char *save);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif