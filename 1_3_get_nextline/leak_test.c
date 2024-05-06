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
    // char *str;
    // int fd;

    // fd = open("./tests/test_a.txt", O_RDONLY);
    // fd = open("./tests/empty.txt", O_RDONLY);
    // fd = open("./tests/1char.txt", O_RDONLY);
    // fd = open("./tests/one_line_no_nl.txt", O_RDONLY);
    // fd = open("./tests/41_with_nl.txt", O_RDONLY);
    // fd = open("./tests/one_line_no_nl.txt", O_RDONLY);
    static char *a;
    a = (char *)malloc(sizeof(char));
    char *b = (char *)malloc(sizeof(char));
    // for(int i = 0; i < 3; i++)
    // {
    //     str = get_next_line(fd);
    //     printf("[%d]%s", i, str);
    // }
    (void)a;
    (void)b;
    
    // free(a);
    // free(b);
    atexit(check_leak);
}