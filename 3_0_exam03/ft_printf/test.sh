gcc -Wall -Werror -Wextra ft_printf.c main.c -o ft_printf
# gcc printf_test.c main_copy.c -o ft_printf
./ft_printf > yy
cat -e yy > y
gcc -D REAL main_copy.c -o printf
./printf | cat -e > r
diff r y
rm -rf yy y r ft_printf printf