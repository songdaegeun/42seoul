#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str) {
	int i = 0;

	while(str[i]) {
		i++;
	}
	return (i);
}

int len_dec(int num) {
	int i = 1;

	while(num/10) {
		num /= 10;
		i++;
	}
	return (i);
}

int len_hex(unsigned int num) {
	int i = 1;

	while(num/16) {
		num /= 16;
		i++;
	}
	return (i);
}


char *find_sdx(char *str) {
	int i = 0;
	while(str[i] && (str[i] >= '0' && str[i] <= '9' || str[i] == '.')) 
		i++;
	if(str[i] == 's' || str[i] == 'd' || str[i] == 'x')
		return (str+i);
	else
		return (0);
}

char *ft_strdup(char *str, int n) {
	char *ret = malloc(n);
	if(!ret)
		return (0);
	ret[n] = '\0';

	int i = 0;
	while(str[i] && i < n) {
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

void ft_putnstr(char *str, int n) {
	int i =0;
	while(i < n) {
		write(1, &str[i], 1);
		i++;
	}
}

void ft_put(long long num, int base) {
	char *dec = "0123456789";
	char *hex = "0123456789abcdef";

	if(num < 0)
		num *= -1;
	if(num >= base) {
		ft_put(num/base, base);
		ft_put(num%base, base);	
	}
	else {
		if(base == 10)
			write(1, &dec[num], 1);
		else if(base == 16)
			write(1, &hex[num], 1);
	}
}

int formating(va_list ap, char *format, char ch) {
	int width = 0;
	int precision = 0;
	int dot = 0;
	int i = 0;
	int ret = 0;
	while(format[i]) {
		if((format[i] >= '0' && format[i] <= '9') && !dot)
			width = width*10 + (format[i] - '0');
		else if(format[i] == '.')
			dot = 1;
		else if((format[i] >= '0' && format[i] <= '9') && dot)
			precision = precision*10 + (format[i] - '0');
		i++;
	}
	// printf("\n:%d %d:\n", width, precision);
	char *str;
	int num = 0;
	unsigned int unum = 0;
	int len;

	if(ch == 's') {
		if(!(str = va_arg(ap,char *)))
			str = "(null)";
		int len = ft_strlen(str);
		if(dot) {
			if(len < precision)
				precision = len;
		}
		else 
			precision = len;
		int i = 0;
		while(i < width - precision) {
			write(1," ",1);
			ret++;
			i++;
		}
		ret+=precision;
		ft_putnstr(str, precision);
	}
	else {
		if(ch == 'd') {
			num = va_arg(ap, int);
			len = len_dec(num);
		}
		else if(ch == 'x') {
			unum = va_arg(ap, unsigned int);
			len = len_hex(unum);
		}
		// printf("%d %d %d %d", num, unum, dot, precision );
		if(num == 0 && unum == 0 && dot && precision == 0) {
			int i = 0;
			while(i<width) {
				write(1," ", 1);
				ret++;
				i++;
			}
		}
		else {
			if(precision < len)
				precision = len;
			if(num < 0) {
				precision++;
				len++;
			}
			int i = 0;
			while(i < width - precision) {
				write(1," ", 1);
				ret++;
				i++;
			}
			if(num < 0) {
				write(1,"-", 1);
			}
			i = 0;

			while(i < precision - len) {
				write(1,"0", 1);
				i++;
			}
			ret += precision;
			if(ch == 'd') {
				ft_put(num, 10);
			}
			else {
				ft_put(unum, 16);
			}
		}
	}
	return (ret);
}

int parsing_str(va_list ap, char *str) {
	int i = 0;
	int len = 0;

	while(str[i]) {
		if(str[i] == '%') {
			char *addr_sdx = find_sdx(str+i+1);
			if(addr_sdx) {
				char *format = ft_strdup(str+i, addr_sdx+1 - (str+i));
				len += formating(ap, format, *addr_sdx);
				free(format);
				i+= (addr_sdx - (str+i));
			}
			else {
				i++;
			}
		}
		else {
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(char const *str, ...) {
	va_list ap;
	int len = 0;

	if(!str)
		return (-1);
	va_start(ap, str);
	len+= parsing_str(ap, (char *)str);

	va_end(ap);
	return(len);
}


int	main(void)
{
	
	ft_printf("%d %d\n", 1,2);
	printf("%d %d\n", 1,2);
	

	// ft_printf("%10.4d %10.4d %10.4d %10.4d %10.4d\n", 42, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	// printf("%10.4d %10.4d %10.4d %10.4d %10.4d \n", 42, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	
	// ft_printf("d10w4p %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	// printf("d10w4p %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	
	// ft_printf("%.d", 0);
	// ft_printf("%4s", "hi~");
	// printf("\n");
	// printf("%.d", 0);
	// printf("%4s", "hi~");
	// printf("\n");
}