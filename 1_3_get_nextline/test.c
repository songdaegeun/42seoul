// gcc -fsanitize=address -D BUFFER_SIZE=42 test.c get_next_line.c get_next_line_utils.c
// gcc -D BUFFER_SIZE=42 test.c get_next_line.c get_next_line_utils.c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	check_leak(void)
{
	system("leaks a.out");
}

int main()
{
    char *str;
    int fd;

    // fd = open("./tests/test_a.txt", O_RDONLY);
    // fd = open("./tests/empty.txt", O_RDONLY);
    // fd = open("./tests/1char.txt", O_RDONLY);
    // fd = open("./tests/one_line_no_nl.txt", O_RDONLY);
    // fd = open("./tests/41_with_nl.txt", O_RDONLY);
	// fd = open("./tests/41_no_nl.txt", O_RDONLY);
	// fd = open("./tests/giant_line_nl.txt", O_RDONLY);
    // fd = open("./tests/one_line_no_nl.txt", O_RDONLY);
	fd = open("./tests/read_error.txt", O_RDONLY);
	// fd = open("./tests/only_nl.txt", O_RDONLY);
	// fd = open("./tests/multiple_nl.txt", O_RDONLY);

	// close(fd);
    // char *a = malloc(sizeof(char));
    // char *b = "";
	int i = 0;
	while(1)
    {
        str = get_next_line(fd);
		if(!str)
			break;
        printf("[%d]%s", i, str);
		free(str);
		i++;
		// system("leaks a.out");
    }
    // free(a);
    // free(b);
	
    // atexit(check_leak);
}