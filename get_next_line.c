/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastane <ecastane@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:25:17 by ecastane          #+#    #+#             */
/*   Updated: 2023/10/07 20:34:59 by ecastane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_read(int fd, char *buffer)
{
	char	*tmp;
	int		read_count;

	read_count = 1;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (ft_free(&buffer));
	tmp[0] = '\0';
	while (read_count > 0 && !ft_strchr(tmp, '\n'))
	{
		read_count = read(fd, tmp, BUFFER_SIZE);
		if (read_count > 0)
		{
			tmp[read_count] = '\0';
			buffer = ft_strjoin(buffer, tmp);
		}
	}
	free(tmp);
	if (read_count == -1)
		return (ft_free(&buffer));
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(buffer, '\n');
	len = (ptr - buffer) + 1;
	line = ft_substr(buffer, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_save(char *buffer)
{
	char	*new_buffer;
	char	*ptr;
	int		len;

	ptr = ft_strchr(buffer, '\n');
	if (!ptr)
	{
		new_buffer = NULL;
		return (ft_free(&buffer));
	}
	else
		len = (ptr - buffer) + 1;
	if (!buffer[len])
		return (ft_free(&buffer));
	new_buffer = ft_substr(buffer, len, ft_strlen(buffer) - len);
	ft_free(&buffer);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((buffer && !ft_strchr(buffer, '\n')) || !buffer)
		buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	if (!line)
		return (ft_free(&buffer));
	buffer = ft_save(buffer);
	return (line);
}
