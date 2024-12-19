#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int  main(int ac, char **av)
{
	int     fd;
	char    *line;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (1);
	int a = 20;
	while (a)
	{
		line = get_next_line(fd);
		write(1, line, ft_strlen(line));
	//	free(line);
		a--;
	}
	/*(close(fd);
	line = get_next_line(fd);
	write(1, line, ft_strlen(line));
	fd = open(av[1], O_RDONLY);
	a = 4;
	while (a)
	{
		line = get_next_line(fd);
		write(1, line, ft_strlen(line));
	//	free(line);
		a--;
	}*/
	close(fd);
	return (0);
}
