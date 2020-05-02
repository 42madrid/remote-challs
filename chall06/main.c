#include <assert.h>
#include <stdio.h>

int ft_check_mate(char *board);

void assert_results(char *board, int expected) {
    int result;

    printf("test: ft_check_mate(\"%s\")\n", board);
    fflush(stdout);
    result = ft_check_mate(board);
    printf("expected_output: %d\nuser_output: %d\n", expected, result);
    fflush(stdout);
    assert(result == expected);
}

int main(void) {
    assert_results("......\n......\n......\n......", 1);
    assert_results("......\n...K..\n...P..\n..K...", 1);
    assert_results("K.....\n......\n......\n......\n......\n......", 1);
    assert_results("K.....\n......\n......\n......", 1);
    assert_results("Z.....\n......\n......\n......\n......\n......", 1);
    assert_results("Z.....\n......\n......\n......", 1);
    assert_results("Q.....\n......\n......\n......\n......\n......", 1);
    assert_results("Q.....\n......\n......\n......", 1);
    assert_results(".", 1);
    assert_results("K", 1);
    assert_results("KKKK\nKKKK\nKKKK\nKKKK", 1);
    assert_results("1234\n1234\n1234\n1234", 1);
    assert_results("1", 1);
    assert_results("1234", 1);
    assert_results("..\n.K", 1);
    assert_results("...\n..\n.KR", 1); //wrong row-size
    assert_results("...\nR.K\n...", 0);
    assert_results("RK\n..", 0);
    assert_results(".R.....K\n........\n........\n........\n........\n........\n........\n........", 0);
    assert_results(".R.....K\n........\n........\n........\n\n........\n........\n........\n........", 1);
    assert_results("\n.R.....K\n........\n........\n........\n........\n........\n........\n........", 1);
    assert_results(".R.....K\n........\n........\n........\n........\n........\n........\n........\n", 1);
    assert_results("RRRRR..K\n........\n........\n........\n........\n........\n........\n........", 0);
    assert_results("..B.....\n........\n........\n........\n........\n.......K\n........\n........", 0);
    assert_results("........\n........\n........\n....B...\n........\n.......K\n........\n........", 1);
    assert_results("..B.....\n........\n........\n........\n......P.\n.......K\n........\n........", 1);
    assert_results("........\n........\n.P....P.\n...B.B..\n....Q...\n..R..R..\n......K.\n...R....", 1);
    assert_results("K.....\n......\n......\n......\n......\n.....B", 0);
    assert_results("K..\n.P.\n...", 0);
    assert_results("...\n.P.\n.K.", 1);
    assert_results(".R......\n........\n........\n........\n........\n.......K\n........\n........", 1);
    assert_results("R.......\n........\n........\n........\n........\nK.......\n........\n........", 0);
    assert_results("K.......\n........\n........\n........\n........\n.......R\n........\n........", 1);
    assert_results("P...P...\n..P.....\n...K....\n.......P\nPPPPPPPP\n.......R\n........\n........", 1);
    assert_results("..Q.....\n........\n........\n........\n........\n.......K\n........\n........", 0);
    assert_results("........\n........\n........\n....Q...\n........\n.......K\n........\n........", 1);
    assert_results("...K....\n...B....\n...B....\n...B....\n...B....\n...B....\n........\n........", 1);
    assert_results(".K....PQ\n........\n........\n........\n........\n........\n........\n........", 1);
    assert_results(".K....PQ\nP.......\n........\n........\n........\n........\n........\n........", 0);
    assert_results(".K....PQ..\nP.........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........", 1);
    assert_results(".K....PQ\nP.......\n........\n........\n........\n........\n........\n.......", 1);
    return (0);
}
