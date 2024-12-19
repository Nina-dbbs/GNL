#include "get_next_line_bonus.h"
#include <stdio.h>

// Classic with and without buffer
// cc -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=15 get_next_line.c get_next_line_utils.c main.c && ./a.out && rm ./a.out 
// cc -Wall -Wextra -Werror -g3 get_next_line.c get_next_line_utils.c main.c && valgrind ./a.out && rm ./a.out 
// cc -Wall -Wextra -Werror -g3 get_next_line.c get_next_line_utils.c main.c && ./a.out && rm ./a.out 

// Bonuses
// cc -Wall -Wextra -Werror -g3 get_next_line_bonus.c get_next_line_utils_bonus.c main.c && ./a.out

int	main(void)
{
	int		lines_count = 15;
	char 	*line = NULL;
	int	fd1 = open("test_files/test1.txt", O_RDONLY);
	//int	fd2 = open("test_files/test2.txt", O_RDONLY);
	int	fd3 = open("test_files/test3.txt", O_RDONLY);

	for (int i = 1; i < lines_count; i++)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		//line = get_next_line(fd2);
		//printf("%s", line);
		//free(line);
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
	}
	close(fd1);
	//close(fd2);
	close(fd3);
}