#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


static int			syntax_check(const char *str) {
	int n = 0;

	while (*str) {
		n += (*str == '(');
		n -= (*str == ')');
		if (n < 0)
			return (0);
		str++;
	}
	return (n == 0); 
}

static const char	*opposite_parenthese(const char *str, int step) {
	char parenthese = (step > 0) ? '(' : ')';
	char opposite = (step > 0) ? ')' : '(';
	int n = 1;

	while (n != 0) {
		n += (*str == parenthese);
		n -= (*str == opposite);
		str += step;
	}
	return (str - step);
}

static char			*hybrid_cpy(const char *src, char *dest, int step) {
	char parenthese = (step > 0) ? '(' : ')';
	char opposite = (step > 0) ? ')' : '(';

	while (*src && *src != opposite) {
		*dest = (*src == parenthese) ? '(' : *src;
		if (*src == parenthese) {
			src = opposite_parenthese(src+step, step);
			dest = hybrid_cpy(src-step, dest + 1, -step);
			*dest = ')';
		}

		src += step;
		dest++;
	}
	*dest = *src;
	return (dest);
}

char				*ft_reverse_parenthesis_solution(const char *str) {
	char *result;

	if (!syntax_check(str))
		return (NULL);

	if (!(result = malloc(strlen(str) + 1)))
		return (NULL);
	hybrid_cpy(str, result, 1);
	return (result);
}
