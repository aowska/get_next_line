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

char    *ft_read(int fd, char *str)
{
    ssize_t nbyte;
    char    *buf;

    buf = NULL;
    nbyte = 1;
    buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buf)
        return (0);
    while(nbyte != 0 || ft_strchr(buf, '\n') == NULL)
    {
        nbyte = read(fd, buf, BUFFER_SIZE);
        if (nbyte == -1)
	    {
		    free(buf);
		    return (NULL);
	    }
        str = ft_strjoin(str, buf);
        free(buf);
    }
    return(str);
}

char    *ft_rests(char *desc)
{
    size_t  i;
    char    *rest;

    i = 0;
    rest = 0;
    i = ft_strlen(ft_strchr(desc, '\n'));
    // if eol == \0 return NULL
	if (!desc[i])
	{
		free(desc);
		return (NULL);
	}
    rest = (char *)malloc((i) * sizeof(char));
    if(!rest)
        return(NULL);
    ft_strcpy(rest, ft_strchr(desc, '\n'));
    rest++;
    return (rest);
}

char *ft_line(char *l, char *s)
{
    int i;

	i = 0;
	while (l[i] && l[i] != '\n')
	{
		s[i] = l[i];
		i++;
	}
    // if eol is \0 or \n, replace eol by \n
	if (l[i] && l[i] == '\n')
		s[i++] = '\n';
	return (s);
}

char *get_next_line(int fd)
{
    static char *line;
    char * str;
    int i;
    
    i = 0;
    str = 0;
    // srawdzamy czy wartosc fd poprawna lub podany buffer jest poprawny 
    if ((fd < 0) || BUFFER_SIZE <= 0)
        return (0);
    line = ft_read(fd, line);
    if(!line)
        return (NULL);
    // find len of first line
	while (line[i] && line[i] != '\n')
		i++;
    str = (char *)malloc((i + 2) * sizeof(char));
    str = ft_line(line, str);
    line = ft_rests(line);
    return(str);
}
//jak malloc dla line ?????