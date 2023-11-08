#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*temp;
	int	fd;

	fd = open("7.rtf", O_RDONLY);

	int i = 0;
	while(i++ < 10)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		printf("%s", temp);
		fflush(0);
		//free(temp);
	}
	close(fd);
	return (0);
}