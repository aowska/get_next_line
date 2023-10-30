/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:10:02 by awacowsk          #+#    #+#             */
/*   Updated: 2023/08/02 21:10:03 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


void	*ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*n;

	n = malloc(number * size);
	if (n != NULL)
		ft_memset(n, 0, number * size);
	return (n);
}
/* number - liczba argumentow
size rozmiar kazdego armunemtu */
char	*ft_strchr(const char *str, int c)
{
	c = (unsigned char)c;
	while ((*str != '\0') && (*str != c))
		str++;
	if (*str == c)
		return ((char *)str);
	return ((char *) NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char const *src)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[a] != '\0')
	{
		dest[i] = src[a];
		a++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char const *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	ptr = (char *)malloc (ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (s1 && s2)
		return (ft_strcat(ft_strcpy(ptr, s1), s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strcpy(ptr, s1));
	else if (s1 == NULL && s2 != NULL)
		return (ft_strcpy(ptr, s2));
	else
		return (NULL);
	return (ptr);
}

