#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	char buffer[BUFFER_SIZE + 1];
	fd = open("test.txt", O_RDONLY);

	if (fd == -1)
	{
		write(1, "ERROR\n", 6);
		return (-1);
	}

	printf("%s", get_next_line(fd));

	return (0);
}