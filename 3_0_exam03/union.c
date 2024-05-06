#include <unistd.h>

void ft_putchar(char ch) {
	write(1,&ch,1);
}

int main(int argc, char** argv)
{ 
	if(argc!=3) {
		ft_putchar('\n');
		return (0);
	}
	char *str1 = argv[1];
	char *str2 = argv[2];
	int i = 0;
	while(str1[i] != 0) {
		int j = 0;
		while(j<i) {
			if(str1[j] == str1[i])
				break;
			j++;
		}
		if(i==j)
			ft_putchar(str1[i]);
		i++;
	}
	i = 0;
	while(str2[i] != 0) {
		int str1_j = 0;
		while(str1[str1_j] != 0) {
			if(str1[str1_j] == str2[i])
				break;
			str1_j++;
		}
		int str2_j = 0;
		while(str2_j < i && str1[str1_j] == 0) {
			if(str2[str2_j] == str2[i])
				break;
			str2_j++;
		}
		if(i==str2_j && str1[str1_j] == 0)
			ft_putchar(str2[i]);
		i++;
	}
	
}

//./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e

