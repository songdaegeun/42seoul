// gcc -fsanitize=address -D BUFFER_SIZE=42 test.c get_next_line.c get_next_line_utils.c
// gcc -D BUFFER_SIZE=10 test_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
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
    int fd1, fd2;

	fd1 = open("./tests/read_error.txt", O_RDONLY);
	fd2 = open("./tests/lines_around_10.txt", O_RDONLY);

    // char *a = malloc(sizeof(char));
    // char *b = "";
    // for(int i = 0; i < 6; i++)
    // {
	// 	if(i%2 == 0)
	//         str = get_next_line(fd1);
	// 	else
	// 		str = get_next_line(fd2);
    //     printf("[%d]%s", i, str);
	// 	free(str);
	// 	// system("leaks a.out");
    // }
	str = get_next_line(fd1);
	printf("[%d]%s", 0, str);
	str = get_next_line(fd1);
	printf("[%d]%s", 1, str);
	str = get_next_line(fd1);
	printf("[%d]%s", 2, str);
	close(fd1);
	fd1 = open("./tests/read_error.txt", O_RDONLY);
	str = get_next_line(fd1);
	printf("[%d]%s", 3, str);
    // free(a);
    // free(b);
	
    // atexit(check_leak);
}