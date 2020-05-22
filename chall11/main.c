#include <stdio.h>
#include <stdlib.h>

char *ft_goto_parser(const char *code);

int main()
{
	const char *code = (
		"1 I am\n"
		"goto 5\n"
		"2 travelling\n"
		"3 down\n"
		"4 the river\n"
		"5 back\n"
		"10 home\n"
	);

	printf("%s", ft_goto_parser(code));
}
