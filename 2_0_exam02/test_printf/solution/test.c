/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:20:30 by dasong            #+#    #+#             */
/*   Updated: 2023/04/13 21:17:44 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf.h"

// gcc test.c -L. -lftprintf -L./libft -lft
// gcc -g -fsanitize=address test.c -L. -lftprintf -L./libft -lft
// %[flags][width][precision]conversion
// flags: # + - ' ' 0
// width: field_width
// precision: .
// conversion: [cspdiuxX%]
// # + -  ' ' 0 field_width . [cspdiuxX%]   << 8개
void	__leak(void)
{
	system("leaks a.out");
}

int	main()
{
	int data1, data2;
    // // printf("%%conversion----------------\n");
    // printf("%c\n", 'c');
    // ft_printf("%c\n", 'c');
    // printf("%s\n", "hi");
    // ft_printf("%s\n", "hi");
    // printf("%p\n", "hi");
    // ft_printf("%p\n", "hi");
    // printf("%d\n", 12);
    // ft_printf("%d\n", 12);
    // printf("%i\n", 12);
    // ft_printf("%i\n", 12);
    // printf("%u\n", 12);
    // ft_printf("%u\n", 12);
    // printf("%x\n", 0xab);
    // ft_printf("%x\n", 0xab);
    // printf("%X\n", 0xab);
    // ft_printf("%X\n", 0xab);
    // printf("%%\n");
    // ft_printf("%%\n");
    // // printf("%%conversion----------------\n");
    // printf("%c\n", 'c');
    // ft_printf("%c\n", 'c');
    // printf("%s\n", "hi");
    // ft_printf("%s\n", "hi");
    // printf("%p\n", "hi");
    // ft_printf("%p\n", "hi");
    // printf("%d\n", -12);
    // ft_printf("%d\n", -12);
    // printf("%i\n", -12);
    // ft_printf("%i\n", -12);
    // printf("%u\n", -12);
    // ft_printf("%u\n", -12);
    // printf("%x\n", -0xab);
    // ft_printf("%x\n", -0xab);
    // printf("%X\n", -0xab);
    // ft_printf("%X\n", -0xab);
    // printf("%%\n");
    // ft_printf("%%\n");
    // printf("%%[width]conversion----------------\n");
    // printf("%25c %d\n", 'c', 2);
    // ft_printf("%25c %d\n", 'c', 2);
    // printf("%25s %d\n", "hi", 2);
    // ft_printf("%25s %d\n", "hi", 2);
    // printf("%25p %d\n", "hi", 2);
    // ft_printf("%25p %d\n", "hi", 2);
    // printf("%25d %d\n", 12, 2);
    // ft_printf("%25d %d\n", 12, 2);
    // printf("%25i %d\n", 12, 2);
    // ft_printf("%25i %d\n", 12, 2);
    // printf("%25u %d\n", 12, 2);
    // ft_printf("%25u %d\n", 12, 2);
    // printf("%25x %d\n", 0xab, 2);
    // ft_printf("%25x %d\n", 0xab, 2);
    // printf("%25X %d\n", 0xab, 2);
    // ft_printf("%25X %d\n", 0xab, 2);
    // // printf("--------------------------------\n");
	// printf("%#25x %d\n", 0xab, 2);
    // ft_printf("%#25x %d\n", 0xab, 2);
	// printf("%#25X %d\n", 0xab, 2);
    // ft_printf("%#25X %d\n", 0xab, 2);
	// printf("%-25d %d\n", 12, 2);
    // ft_printf("%-25d %d\n", 12, 2);
	// printf("%+25d %d\n", 12, 2);
    // ft_printf("%+25d %d\n", 12, 2);
	// printf("%+25d %d\n", -12, 2);
    // ft_printf("%+25d %d\n", -12, 2);
	// printf("%025d %d\n", 12, 2);
    // ft_printf("%025d %d\n", 12, 2);
	// printf("%25.3s %d\n", "abcd", 2);
    // ft_printf("%25.3s %d\n", "abcd", 2);
	// printf("%25.3s %d\n", "hi", 2);
    // ft_printf("%25.3s %d\n", "hi", 2);
	// printf("paco--------------------------------\n");
	// printf("");
	// ft_printf("");
	// printf(" %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	// ft_printf(" %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	// printf(" NULL %-10s NULL \n", (char *)NULL);
	// ft_printf(" NULL %-10s NULL \n", (char *)NULL);
	// printf(" NULL %-10c NULL \n", 0);
	// ft_printf(" NULL %-10c NULL \n", 0);
	// printf(" %d %d %d %d\n", INT_MAX, INT_MIN, 0, -42);
	// ft_printf(" %d %d %d %d\n", INT_MAX, INT_MIN, 0, -42);
	// data1 = printf(" %c %c %c \n", '0', 0, '1');
	// data2 = ft_printf(" %c %c %c \n", '0', 0, '1');
	// data1 = printf(" %c %c %c \n", '2', '1', 0);
	// data2 = ft_printf(" %c %c %c \n", '2', '1', 0);
	// data1 = printf(" %c %c %c \n", 0, '1', '2');
	// data2 = ft_printf(" %c %c %c \n", 0, '1', '2');
	// printf("%%%c\n", 'x');
	// ft_printf("%%%c\n", 'x');
	// printf("%s\n", "");
	// ft_printf("%s\n", "");
	// data1 = printf("%%%c\n", 'A');
	// data2 = ft_printf("%%%c\n", 'A');
	// data1 = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// data2 = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// data1 = printf("a%c\n", 0);
	// data2 = ft_printf("a%c\n", 0);	
	// // 0이 들어가서 중간에 str이 한번 끊기는 문제 non-printable char 대입으로 해결? 안됨. null문자를 출력해야함. ch_join으로 res를 string으로 관리하는것이 아닌, 
	// // 길이를 멤버변수로 갖고 있으면서 캐릭터를 한개씩 추가할 수 있는 연결리스트 or 매번 realloc하고 값복사 하는 방식(가변길이배열)의 자료구조로 res를 관리해야함.
	// // printf("[-0.]combination--------------------------------\n");
	// printf("%25.5d%c\n", 1234, '$');
	// ft_printf("%25.5d%c\n", 1234, '$');
	// printf("%025.5d%c\n", 1234, '$');		//ignore 0
	// ft_printf("%025.5d%c\n", 1234, '$');
	// printf("%-25.5d%c\n", 1234, '$');
	// ft_printf("%-25.5d%c\n", 1234, '$');
	// printf("%-025.5d%c\n", 1234, '$');			// error: flag '0' is ignored when flag '-' is present [-Werror,-Wformat]
	// ft_printf("%-025.5d%c\n", 1234, '$');
	// printf("%0-25.5d%c\n", 1234, '$');				// error: flag '0' is ignored when flag '-' is present [-Werror,-Wformat]
	// ft_printf("%0-25.5d%c\n", 1234, '$');
    // printf("%.-5d%c\n", 1234, '$');				// conversion값이 음수가 될 경우, precision은 omit(.0)으로 처리되고 width가 5, flag는 -로 처리.
	// printf("%-5.d%c\n", 1234, '$');
	// ft_printf("%.-5d%c\n", 1234, '$');
	// printf("%.-5s%c\n", "1234", '$');			// conversion값이 음수가 될 경우, precision은 omit(.0)으로 처리되고 "width가 5, flag는 -로 처리"(메뉴얼에 없음).
	// printf("%5.s%c\n", "1234", '$');
	// ft_printf("%.-3s%c\n", "1234", '$');
	// ft_printf("%.-3s%c\n", "1234", '$');
	// printf("%.d%c\n", -1234, '$');
	// ft_printf("%.d%c\n", -1234, '$');
	// printf("d1: %d, d2: %d\n", data1, data2); 
	// printf("-----------\n");
	// printf(" %+06d %c\n", -14, '$');
	// printf(" %+06d %c\n", +14, '$');
	// ft_printf(" %06d %c\n", -14, '$');
	// ft_printf(" %+06d %c\n", +14, '$');

	// ft_printf(" %-06d %c\n", -14, '$');
	// ft_printf(" %-06d %c\n", +14, '$');
	// ft_printf(" %6d %c\n", -14, '$');
	// ft_printf(" %+6d %c\n", -14, '$');
	// ft_printf(" %+6d %c\n", +14, '$');
	// ft_printf(" %-6d %c\n", -14, '$');
	// ft_printf(" %-6d %c\n", +14, '$');

	// printf(" %-06d %c\n", -14, '$');
	// ft_printf(" %-06d %c\n", -14, '$');
	// printf(" %+06d %c\n", 14, '$');
	// ft_printf(" %+06d %c\n", 14, '$');
	// printf(" %+06d %c\n", -14, '$');
	// ft_printf(" %+06d %c\n", -14, '$');
	// printf(" %+06d %c\n", 14, '$');
	// ft_printf(" %+06d %c\n", 14, '$');
	// printf(" %#+-06d %c\n", 14, '$');
	// ft_printf(" %#+-06d %c\n", 14, '$');
	// printf("bonus-----------------------------------------\n");

	// printf("%-11p,%-12p$\n", INT_MIN, INT_MAX);
	// ft_printf("%-11p,%-12p$\n", INT_MIN, INT_MAX);

	// printf("%0#41x\n", 15);
	// ft_printf("%0#41x\n", 15);

	// printf("%#60.42x$\n", 15);
	// ft_printf("%#60.42x$\n", 15);

	// printf("%0#62.50x\n", 15);
	// ft_printf("%0#62.50x\n", 15);
	
	// printf("%#-42.48x\n", 12);
	// ft_printf("%#-42.48x\n", 12);

	// printf("%#034x\n", 12);
	// ft_printf("%#034x\n", 12);


	printf("%0#x\n", -12);
	ft_printf("%0#x\n", -12);

	
// [ERROR] diff on output for format "42%#54.42x42" and arg: -1281129056
// expected: [42          0x0000000000000000000000000000000000b3a385a042]
//      got: [420x          0000000000000000000000000000000000b3a385a042]

	// printf("%0#41p\n", 15);
	// ft_printf("%0#41p\n", 15);
	// printf("%d", data);
	// atexit(__leak);
}
