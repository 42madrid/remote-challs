#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define RAND() (rand() & 0x7fff)

char *ft_format_duration(char *seconds);
char *ft_format_duration_solution(char *seconds);

void assert_results(char *seconds) {
    char *output;
    char *expected;

    printf("test: ft_format_duration(\"%s\")\n", seconds);
    fflush(stdout);
    output = ft_format_duration(seconds);
    expected = ft_format_duration_solution(seconds);
    printf("expected_output: %s\nuser_output: %s\n", expected, output);
    fflush(stdout);
    assert(strcmp(output, expected) == 0);
    // free(output);
    free(expected);
}

int main(void) {
    size_t              i;
    unsigned long long  n;
    char                *seconds;

    assert_results("0");
    assert_results("60");
    assert_results("61");
    assert_results("62");
    assert_results("63");
    assert_results("64");
    assert_results("4242");
    assert_results("1328218962");
    assert_results("asdad");
    assert_results("4asdad");
    assert_results("-41212");
    assert_results("4214 21421");
    assert_results("-214");
    assert_results("9999999999999999999");
    assert_results("10000000000000000000");
    assert_results("10000000000000000001");
    assert_results("4214032131247127411461641468712641471241241826481264821421");
    srand(time(0));

    for (i = 0; i < 100; i++) {
        n = ((unsigned long long)RAND()<<48) ^ ((unsigned long long)RAND()<<35) ^ ((unsigned long long)RAND()<<22) ^
            ((unsigned long long)RAND()<< 9) ^ ((unsigned long long)RAND()>> 4);
        seconds = malloc(sizeof(char) * 256);
        sprintf(seconds, "%llu", n);
        assert_results(seconds);
        free(seconds);
    }
    return (0);
}
