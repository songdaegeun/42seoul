// gcc test_bouns.c
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *tmp_buff;

    tmp_buff = (char *)malloc(sizeof(char) * 0);
    printf("ft:%p\n", tmp_buff);
}