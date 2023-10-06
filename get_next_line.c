/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastane <ecastane@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:25:17 by ecastane          #+#    #+#             */
/*   Updated: 2023/10/06 23:46:25 by ecastane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *save)
{
	char	*tmp;
	int		read_rtn;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	read_rtn = 1;
	while (!ft_strchr(save, '\n') && read_rtn > 0)
	{
		read_rtn = read(fd, tmp, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(tmp);
			if (save)
				free(save);
			return (NULL);
		}
		else if (read_rtn == 0)
			break ;
		tmp[read_rtn] = '\0';
		save = ft_strjoin(save, tmp);
	}
	free(tmp);
	return (save);
}

char	*ft_get_line(char *save)
{
	size_t		i;
	char		*s;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	s = ft_substr(save, 0, i);
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_save(char *save)
{
	size_t		i;
	char		*s;

	if (!save)
	{
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || !save[i + 1])
	{
		free(save);
		return (NULL);
	}
	s = ft_substr(save, i + 1, BUFFER_SIZE);
	free(save);
	if (!s)
		return (NULL);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
	{
		free(save);
		return (NULL);
	}
	line = ft_get_line(save);
	if (!line)
		free(line);
	save = ft_save(save);
	return (line);
}
