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
	char	*temp;

	buf = NULL;
	temp = NULL;
	nbyte = 1;
	if (!str) 
	{
		str = (char *)malloc(1 * 1);
		*str = 0;
	}
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free(str), NULL);
	while (nbyte > 0 && !ft_strchr(str, '\n'))
	{
		nbyte = read(fd, buf, BUFFER_SIZE);
		if (nbyte == -1)
			return (free(buf), free(str), NULL);
		buf[nbyte] = '\0';
		temp = ft_strjoin(str, buf);
		if (!temp)
			return (free(str), free(buf), NULL);
		free(str); 
		str = temp;
	}
	return (free(buf), str);
}

char	*ft_rests(char *desc)
{
	char	*rest;
	size_t	i;

	rest = NULL;
	i = 0;
	while (desc[i] && desc[i] != '\n')
		i++;
	if (!desc[i])
		return (free(desc), NULL);
	rest = (char *)malloc((ft_strlen(desc) - i + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	if (ft_strchr(desc, '\n'))
		ft_strcpy(rest, ft_strchr(desc, '\n') + 1);
	return (free(desc), rest);
}

char	*ft_line(char *l)
{
	size_t	i;
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
	if (l[i] && l[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;

	str = NULL;
	if ((fd < 0) || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = ft_read(fd, line);
	if (!line)
		return (NULL);
	str = ft_line(line);
	line = ft_rests(line);
	return (str);
}
