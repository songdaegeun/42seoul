#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_buff {
	char *buff;
	int size;
	int capacity;
} t_buff;


char *gnl(int fd);
int init_buff(t_buff *p_buff);
char *ret_save_buff(t_buff *p_buff);
int chk_size(t_buff *p_buff);
int load_buff(int fd, t_buff *p_buff);

int main()
{
	int fd = open("./text/read_error.txt", O_RDONLY);

	char *str = gnl(fd);
	printf("%s\n", str);
}

char *gnl(int fd) {
	static t_buff buff;
	char *res;
	#ifndef BUFF_SIZE
	#define BUFF_SIZE 42
	#endif

	if(buff.capacity == 0 && !init_buff(&buff))
		return (0);
	load_buff(fd, &buff);
	res = ret_save_buff(&buff);
	return (res);
}

int init_buff(t_buff *p_buff) {
	p_buff->capacity = 1024;
	p_buff->size = 0;
	p_buff->buff = (char *)malloc(sizeof(char) * p_buff->capacity);
	if(p_buff->buff) {
		return (0);
	}
	return (1);
}

char *ret_save_buff(t_buff *p_buff) {
	// '\n'전까지 ret하고 그 이후를 buff에 남긴다.
	char *ret_line;
	int size;

	for (size = 0; size < p_buff->size; size++)
	{
		if(p_buff->buff[size] == '\n') {
			size++;
			break;
		}
	}
	if (size == 0) 
		return (0);
	ret_line = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret_line)
		return (0);
	ret_line[size] = 0;
	int i = -1;
	while (++i < size)
	{
		ret_line[i] = p_buff->buff[i];
		if (p_buff->buff[i] == '\n')
			break ;
	}
	i = -1;
	while (++i < (p_buff->size - size))
		(p_buff->buff)[i] = (p_buff->buff + size)[i];
	p_buff->size = p_buff->size - size;
	return (ret_line);
}

int chk_size(t_buff *p_buff) {

	char *tmp_buff;

	if(p_buff->size == p_buff->capacity) {
		p_buff->capacity *= 2;
		tmp_buff = (char *)malloc(sizeof(char) * p_buff->capacity);
		if(tmp_buff) {
			free(p_buff->buff);
			return (0);
		}
		for (int i = 0; i < p_buff->size; i++)
		{
			tmp_buff[i] = p_buff->buff[i];
		}
		free(p_buff->buff);
		p_buff->buff = tmp_buff;
	}
	return (1);
}

int load_buff(int fd, t_buff *p_buff) {
	
	char temp_buff[BUFF_SIZE];
	int read_size = 0;

	while(1) {

		for (int i = 0; i < p_buff->size; i++)
		{
			if(p_buff->buff[i] == '\n')
				break;
		}		
		
		read_size = read(fd, temp_buff, BUFF_SIZE);
		if(read_size <= 0) {
			break;
		}
		for (int i = 0; i < read_size; i++)
		{
			p_buff->buff[p_buff->size++] = temp_buff[i];
			if(!chk_size(p_buff)) {
				return (1);
			}
		}
	}
	if(read_size < 0) 
		return (0);
	return (1);
}
