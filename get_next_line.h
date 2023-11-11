/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:09:53 by awacowsk          #+#    #+#             */
/*   Updated: 2023/08/02 21:09:54 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *string, int i);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char const *src);
char	*ft_strcat(char *dest, char const *src);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t number, size_t size);

#endif
