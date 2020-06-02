#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_goto_parser(const char *code);
char *ft_goto_parser_solution(const char *code);

void assert_results(const char *code) {
    char        *output;
    char        *expected;
    static size_t      i = 1;

    printf("test nb %zu: ft_goto_parser(\"%s\")\n", i++, code);
    fflush(stdout);
    expected = ft_goto_parser_solution(code);
    printf("expected_output: %s\n", expected);
    fflush(stdout);
    output = ft_goto_parser(code);
    printf("user_output: %s\n\n", output);
    fflush(stdout);
    assert(strcmp(output, expected) == 0);
    // free(output);
    // free(expected);
}

int main(void) {
    const char  *code1 = "5 HERE\ngoto  10  \n10 IS\ngoto 40\n20 JUST rAnDoM TEXT\n30 AND\n40 MORE RANDOM text\n";
    assert_results(code1);
    const char  *code2 = "1 I am\ngoto 5\n2 travelling\n3 down\n4 the river\n5 back\n10 home\n";
    assert_results(code2);
    const char  *code3 = "1              I         \ngoto      5       \n2 travelling\n3   down  \n4 the river\n5           love        being     \n10                in      42.\n";
    assert_results(code3);
    const char  *code4 = "1 I am\n2 travelling\n3 down\ngoto 2\n4 the river\n5 back\n10 home\n";
    assert_results(code4);
    const char  *code5 = "1 I am\ngoto 4\n2 travelling\n3 down\ngoto 2\n4 the river\n5 that just\n10 keeps flowing\n";
    assert_results(code5);
    const char  *code6 = "1 I am\ngoto 4\n2 travelling\n3 down\ngoto 2\n4 the river\n5 that just\n10 keeps flowing\n";
    assert_results(code6);
    const char  *code7 = "1024 I         \ngoto      64       \n512 travelling\n256   down  \n128 the river\n64           love        being     \n32 in      42.\n";
    assert_results(code7);
    const char  *code8 = "1024 I         \ngoto      512       \n512 travelling\ngoto   64  \n128 the river\n64           love        being     \n32 in      42.\n";
    assert_results(code8);
    const char  *code9 = "1 a\ngoto 3\n2 B\n3 c\ngoto 5\n4 D\n5 e\ngoto 7\n6 F\n7 g\n";
    assert_results(code9);
    const char  *code10 = "15 To be\n20 or\n25 not\n27 to be.\n";
    assert_results(code10);
    const char  *code11 = "goto 13\n12 Banana wrists\n13 Strawberry fields\ngoto 14\n14 Raspberry wishes\n15 I forgot\ngoto 16\n16 the lyrics\n";
    assert_results(code11);
    const char  *code12 = "5 HERE\ngoto         50\n10 IS\n20 JUST rAnDoM TEXT\ngoto         80\n30 AND\n40 MORE RANDOM text\n50 HERE2\ngoto 20\n60 IS2\n70 JUST rAnDoM TEXT2\n80 AND2\n90 MORE RANDOM text2\n";
    assert_results(code12);
    return (0);
}
