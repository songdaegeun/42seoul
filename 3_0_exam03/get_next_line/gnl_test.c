
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strdup(char *str,int num) {
	int i  = 0;
	char *ret = malloc(sizeof(str) + 1);
	if(ret < 0)
		return (0);
	ret[sizeof(str)] = '\0';
	while(str[i] && i < num) {
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

int ft_strlen(char *str) {
	int i = 0;
	while(str[i]) {
		i++;
	}
	return (i);
}

char *ft_strcat(char *str1, char *str2) {
	int size1 =ft_strlen(str1);
	int size2 =ft_strlen(str2);
	char *ret = malloc(sizeof(char)*(size1+size2+1));
	if(ret < 0)
		return (0);
	ret[size1+size2] = '\0';
	int i=0;
	while(i < size1) {
		ret[i] = str1[i];
		i++;
	}
	while(i - size1 < size2) {
		ret[i] = str2[i - size1];
		i++;
	}
	return (ret);
}

char *ft_strch(char *str, char ch) {
	int i = 0;
	while(str[i]) {
		if(str[i] == ch)
			return (str+i);
		i++;
	}
	if(ch == '\0')
		return (str+i);
	else
		return (0);
}

int get_next_line(char **line) {
	char *buf = malloc(sizeof(char)*2);
	if(!buf)
		return (-1);
	static char *data; 
	char *tmp;
	char *ret;

	if(!data) {
		data = ft_strdup("",1);
		while (read(0,buf,1) > 0) {
			tmp = data;
			data = ft_strcat(data, buf);
			free(tmp);
		}
	}
	char *split_addr = ft_strch(data, '\n');
	if(split_addr) {
		*line = ft_strdup(data, split_addr - data);
		data += split_addr - data + 1;
		return (1);
	}
	else {
		*line = ft_strdup(data, ft_strch(data, '\0')-data);
		return (0);
	}
}

int main() {
	int ret;
	char *line;

	while((ret = get_next_line(&line)) > 0) {
		printf("%d %s\n", ret, line);
		free(line);
	}
	printf("%d %s\n", ret, line);
	free(line);
}