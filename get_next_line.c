/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:09:43 by awacowsk          #+#    #+#             */
/*   Updated: 2023/08/02 21:09:44 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	ssize_t	nbyte;
	char	*buf;

	buf = NULL;
	nbyte = 1;
	if (!str)
		str = (char *)malloc(1 * 1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		free(buf);
		return (0);
	}
	while (nbyte > 0 && !ft_strchr(str, '\n'))
	{
		nbyte = read(fd, buf, BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[nbyte] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*ft_rests(char *desc)
{
	char	*rest;
	size_t	i;

	rest = NULL;
	i = 0;
	while (desc[i] && desc[i] != '\n')
		i++;
	if (!desc)
	{
		free(desc);
		return (NULL);
	}
	rest = (char *)malloc((ft_strlen(desc) - i + 1) * sizeof(char));
	if (!rest)
	{
		free(desc);
		return (NULL);
	}
	if (ft_strchr(desc, '\n'))
		ft_strcpy(rest, ft_strchr(desc, '\n') + 1);
	else
		rest[i] = '\0';
	free(desc);
	return (rest);
}

char	*ft_line(char *l)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL; 
	if (!l[i])
		return (NULL);
	while (l[i] && l[i] != '\n')
		i++;
	s = (char *)malloc((i + 2) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (l[i] && l[i] != '\n')
	{
		s[i] = l[i];
		i++;
	}
	if (l[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;

	str = NULL;
	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read(fd, line);
	if (!line)
		return (NULL);
	str = ft_line(line);
	line = ft_rests(line);
	return (str);
}
