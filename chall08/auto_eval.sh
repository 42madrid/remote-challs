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
    echo "#1 base test case" | tee -a $expected_file $output_file
    cat test_cases/test_case1.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case1.txt | ./$i &>> $output_file
    echo "#2 Two robots" | tee -a $expected_file $output_file
    echo "./${output}.py: Invalid input." >> $expected_file
    cat test_cases/test_case2.txt | ./$i &>> $output_file
    echo "#3 Two exit points" | tee -a $expected_file $output_file
    echo "./${output}.py: Invalid input." >> $expected_file
    cat test_cases/test_case3.txt | ./$i &>> $output_file
    echo "#4 Not a closed square" | tee -a $expected_file $output_file
    echo "./${output}.py: Invalid input." >> $expected_file
    cat test_cases/test_case4.txt | ./$i &>> $output_file
    echo "#5 Not a closed square 2" | tee -a $expected_file $output_file
    echo "./${output}.py: Invalid input." >> $expected_file
    cat test_cases/test_case5.txt | ./$i &>> $output_file
    echo "#6 Not a closed square 3 (Exit in corner)" | tee -a $expected_file $output_file
    echo "./${output}.py: Invalid input." >> $expected_file
    cat test_cases/test_case6.txt | ./$i &>> $output_file
    echo "#7 Wrong input" | tee -a $expected_file $output_file
    echo "./${output}.py: Invalid input." >> $expected_file
    cat test_cases/test_case7.txt | ./$i &>> $output_file
    echo "#8 Through the mines" | tee -a $expected_file $output_file
    cat test_cases/test_case8.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case8.txt | ./$i &>> $output_file
    echo "#9 Against the wall" | tee -a $expected_file $output_file
    cat test_cases/test_case9.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case9.txt | ./$i &>> $output_file
    echo "#10 Against the wall x2" | tee -a $expected_file $output_file
    cat test_cases/test_case10.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case10.txt | ./$i &>> $output_file
    echo "#11 Mines before turning on" | tee -a $expected_file $output_file
    cat test_cases/test_case11.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case11.txt | ./$i &>> $output_file
    echo "#12 Mines after turning on" | tee -a $expected_file $output_file
    cat test_cases/test_case12.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case12.txt | ./$i &>> $output_file
    echo "#13 Turn on a lot of times" | tee -a $expected_file $output_file
    cat test_cases/test_case13.txt | ./solution.py &>> $expected_file
    cat test_cases/test_case13.txt | ./$i &>> $output_file
    echo "#14 Invalid chars in instructions" | tee -a $expected_file $output_file
    echo "./${output}.py: Invalid input." >> $expected_file
    cat test_cases/test_case14.txt | ./$i &>> $output_file
    echo "#15 Invalid chars in board" | tee -a $expected_file $output_file
    echo "./${output}.py: Invalid input." >> $expected_file
    cat test_cases/test_case15.txt | ./$i &>> $output_file
    echo "#16 Hard test case" | tee -a $expected_file $output_file
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
