/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastane <ecastane@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:53:59 by ecastane          #+#    #+#             */
/*   Updated: 2023/10/07 00:15:45 by ecastane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	return_len;

	if(!s)
		return (0);
	return_len = 0;
	while (s[return_len])
		return_len ++;
	return (return_len);
}

char	*ft_strchr(char *string, int searchedChar)
{
	char	*str;

	if (!string)
		return (NULL);
	str = (char *)string;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	c;
	char	*rtn;
	int		sizetotal;

	i = 0;
	c = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	if (!sizetotal)
		return (NULL);
	rtn = malloc((sizetotal + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
			rtn[i] = s1[i];
			i++;
	}
	while (s2 && s2[c] != '\0')
		rtn[i++] = s2[c++];
	rtn[sizetotal] = '\0';
	return (rtn);
}

char	*ft_strdup(char const *s)
{
	char		*new_s;
	size_t		len;
	size_t		i;

	len = ft_strlen(s);
	new_s = malloc((len +1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;

	if (!s || s[0] == '\0')
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subs = malloc(sizeof(char) * (len + 1));
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
