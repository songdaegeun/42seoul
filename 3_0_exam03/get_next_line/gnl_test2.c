#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int ft_strlen(char *str) {
	int i = 0;
	while(str[i]) {
		i++;
	}
	return (i);
}

char *ft_strch(char *str1, char ch) {
	int i = 0;
	while(str1[i]) {
		if(str1[i] == ch)
			return (str1 + i);
		i++;
	}
	if(ch == '\0')
		return (str1 + i);
	else 
		return (0);
}

char *ft_strdup(char *str1, int n) {
	int i = 0;
	char *ret = malloc(n);
	if(!ret)
		return (0);
	ret[n] = '\0';

	while(str1[i] && i < n) {
		ret[i] = str1[i];
		i++;
	}
	return (ret);
}

char *ft_strcat(char *str1, char *str2) {
	int size1 = ft_strlen(str1);
	int size2 = ft_strlen(str2);
	char *ret = malloc(size1+size2);
	if(!ret)
		return (0);
	ret[size1+size2] = '\0';
	int i = 0;
	while(i < size1) {
		ret[i] = str1[i];
		i++;
	}
	while(i-size1 < size2) {
		ret[i] = str2[i-size1];
		i++;
	}
	return (ret);
}

int get_next_line(char **line) {
	static char *data;
	char *buf = malloc(2);
	if(!buf)
		return (0);
	buf[1] = '\0';

	if(!data) {
		data = ft_strdup("",1);
		char *tmp;
		while(read(0,buf,1) > 0) {
			tmp = data;
			data = ft_strcat(data, buf);
			free(tmp);
		}
	}
	char *ch_addr = ft_strch(data, '\n');
	if(ch_addr) {
		*line = ft_strdup(data, ch_addr-data);
		data += ch_addr-data+1;
		return (1);
	}
	else {
		*line = ft_strdup(data, ft_strch(data, '\0')-data);
		return (0);
	}
}


int main() {
	char *line;
	int ret;
	while((ret = get_next_line(&line))) {
		printf("%d %s\n", ret, line);
		free(line);
	}
	printf("%d %s\n", ret, line);
	free(line);
	return (0);
}