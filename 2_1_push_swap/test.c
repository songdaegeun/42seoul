#include <stdio.h>

int main()
{
	// $ ./push_swap 3 2 2147483648 | cat -e  # INT 범위를 초과한 경우
	// Error$
	
	//---

	// ARG="4 67 3 87 23"; ./push_swap $ARG

    // $ ./push_swap 3 2 2 4 | cat -e    # 중복 에러
	// Error$

	// $ ./push_swap 3 2 one | cat -e  # 정수가 아닌 경우
	// Error$

	// $ ./push_swap "" 1 | cat -e  # 정수가 아닌 경우
	// Error$
}