#!/bin/zsh
rm -rf tmp traces
mkdir -p tmp traces
ok=()
not_ok=()
for i in *.py; do
    # skip main.c file
    if [[ $i == "solution.py" ]]; then
        continue
    fi
    output=${i%.*}
    trace="traces/${output}_trace.txt"
    expected_file="./tmp/${output}_expected.txt"
    output_file="./tmp/${output}_output.txt"
    echo "Processing: $output"
    echo "#1 Base test case" | tee -a $expected_file $output_file
    cat test_cases/test_case1.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case1.txt | ./$i &>> $output_file
    echo "#2 Harder test case" | tee -a $expected_file $output_file
    cat test_cases/test_case2.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case2.txt | ./$i &>> $output_file
    echo "#3 Empty" | tee -a $expected_file $output_file
    cat test_cases/test_case3.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case3.txt | ./$i &>> $output_file
    echo "#4 Two lines" | tee -a $expected_file $output_file
    cat test_cases/test_case4.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case4.txt | ./$i &>> $output_file
    echo "#5 Simple draw" | tee -a $expected_file $output_file
    cat test_cases/test_case5.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case5.txt | ./$i &>> $output_file
    echo "#6 Wrong column name" | tee -a $expected_file $output_file
    cat test_cases/test_case6.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case6.txt | ./$i &>> $output_file
    echo "#7 3 teams" | tee -a $expected_file $output_file
    cat test_cases/test_case7.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case7.txt | ./$i &>> $output_file
    echo "#8 First char in team is not uppercase" | tee -a $expected_file $output_file
    cat test_cases/test_case8.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case8.txt | ./$i &>> $output_file
    echo "#9 Wrong column name 2" | tee -a $expected_file $output_file
    cat test_cases/test_case9.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case9.txt | ./$i &>> $output_file
    echo "#10 Wrong column name 3" | tee -a $expected_file $output_file
    cat test_cases/test_case10.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case10.txt | ./$i &>> $output_file
    echo "#11 Base test case 2" | tee -a $expected_file $output_file
    cat test_cases/test_case11.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case11.txt | ./$i &>> $output_file
    echo "#12 Column overflow" | tee -a $expected_file $output_file
    cat test_cases/test_case12.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case12.txt | ./$i &>> $output_file
    echo "#13 Bigger test case" | tee -a $expected_file $output_file
    cat test_cases/test_case13.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case13.txt | ./$i &>> $output_file
    # Not fair test case
    # echo "#14 Too big test case" | tee -a $expected_file $output_file
    # cat test_cases/test_case14.txt | ./solution.py &>> $expected_file
    # cat test_cases/test_case14.txt | ./$i &>> $output_file
    # Not fair test case
    # echo "#15 Only one team plays" | tee -a $expected_file $output_file
    # cat test_cases/test_case15.txt | ./solution.py &>> $expected_file
    # cat test_cases/test_case15.txt | ./$i &>> $output_file
    echo "#16 Both players win" | tee -a $expected_file $output_file
    cat test_cases/test_case16.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case16.txt | ./$i &>> $output_file
    diff $expected_file $output_file >> $trace
    if [[ $? -eq 0 ]]; then
        echo "Diff: OK" >> $trace
        ok+=($i)
    else
        echo "Diff: KO" >> $trace
        not_ok+=($i)
    fi
done
echo "OK: $ok"
echo "NOT_OK: $not_ok"
