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
		if(i==j) {
			int str2_j = 0;
			while(str2[str2_j] != 0) {
				if(str2[str2_j] == str1[i]) {
					ft_putchar(str1[i]);
					break;
				}
				str2_j++;
			}
		}
		i++;
	}
}

// ./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$