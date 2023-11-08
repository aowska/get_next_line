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

char   *ft_read(int fd, char *str)
{
    ssize_t nbyte;
    char    *buf;

    buf = NULL;
    nbyte = 1;
    if(!str)
        str = (char *)malloc(1 * 1);
    buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // mallocuje piersze spotkane miejsce wiec kurwa nie zwalniaj czegos czego nie mozesz !!!
    //printf("str: %lld, buf : %lld\n", (long long)str, (long long)buf);
    if(!buf)
    {
        free(buf);
        return (0);
    }
    while(nbyte > 0 )
    {
        buf[0] = 0;
        // printf("str: %lld, buf : %lld\n", (long long)str, (long long)buf);
      //  printf("str: %s\n", str);
      //  fflush(0);
        nbyte = read(fd, buf, BUFFER_SIZE);
      //  printf("str2: %s\n", str);
      //  fflush(0);
        if (nbyte == -1)
	    {
		    free(buf);
            free(str);
		    return (NULL);
        }
        buf[nbyte] = '\0';
     //   printf("nbyte: %zd\n", nbyte);
    //    printf("buf: %s\n", buf);
     //   fflush(0);
      //  if (nbyte == 0 || !buf[0])
        //    return (printf("test"), str);
	   // if(buf[0]== '\0')
        //    break;
        str = ft_strjoin(str, buf);
        if(ft_strchr(str, '\n'))
            break ;
    }
   free(buf);
   // printf("%s\n", str);
    return(str);
}

char    *ft_rests(char *desc, int j)
{
   // size_t  i;
    char    *rest;

    rest = 0;
    //printf("i: %zi\n", i);
    // printf("i: %zi\n", i);
    // if eol == \0 return NULL
	if (!desc)
	{
		free(desc);
		return (NULL);
	}
    rest = (char *)malloc((j) * sizeof(char));
    if(!rest)
    {
        free(desc);
        return(NULL);
    }
    if(ft_strchr(desc, '\n'))
        ft_strcpy(rest, ft_strchr(desc, '\n')+ 1);
    else
        free(rest);
    //rest++;
	//printf("%s", rest);
    free(desc);
    return (rest);
}

char *ft_line(char *l, char *s)
{
    int i;

	i = 0;
    if (!l[i])
        return(NULL);
	while (l[i] && l[i] != '\n')
	{
		s[i] = l[i];
		i++;
	}
    // if eol is \0 or \n, replace eol by \n
	if (l[i] || l[i] == '\n')
		s[i++] = '\n';
	return (s);
}

char *get_next_line(int fd)
{
    static char *line;
    char * str;
    int i;
    size_t j;
    
    i = 0;
    str = 0;
    // srawdzamy czy wartosc fd poprawna lub podany buffer jest poprawny 
    if ((fd < 0) || BUFFER_SIZE <= 0)
        return (0);
    //printf("line: %lld\n", (long long)line);
    line = ft_read(fd, line);
    if(!line)
        return (NULL);
    //ind len of first line
    //printf("%s\n", line);
	while (line[i] && line[i] != '\n')
		i++;
    str = (char *)malloc((i + 2) * sizeof(char));
    if(!str)
    {
        free(str);
        return (0);
    }
    j = ft_strlen(line) - i; 
    //str = line;
    str = ft_line(line, str);
   // printf("line pre: %s\n", str);
    line = ft_rests(line, j);
   // printf("rests: %s\n", line);
    return(str);
}

//something is worng with this fucking rests function !! 