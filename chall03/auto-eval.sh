#!/bin/zsh

rm -rf tmp
rm -rf traces
mkdir -p tmp
mkdir -p traces

ok=()
not_ok=()

function randomtest() {
    trace="traces/${1}_trace.txt"
    expected_file="./tmp/${1}_expected.txt"
    output_file="./tmp/${1}_output.txt"
    args=$(./generator.py ${2})

    echo "test: ${args}" | tee -a $expected_file $output_file
    echo ${args} | xargs ./solution.py ./${1}.py &>> $expected_file
    echo ${args} | xargs ./${1}.py &>> $output_file
}

for i in *.py; do
    # skip main.c file
    if [[ $i == "solution.py" ]] || [[ $i == "generator.py" ]]; then
        continue
    fi

    output=${i%.*}
    trace="traces/${output}_trace.txt"
    expected_file="./tmp/${output}_expected.txt"
    output_file="./tmp/${output}_output.txt"
    echo "Processing: $output"

	echo "test: #(noargs)" | tee -a $expected_file $output_file
    ./solution.py ./${output}.py &>> $expected_file
    ./${i} &>> $output_file

    echo "test: 345 234" | tee -a $expected_file $output_file
    ./solution.py ./${output}.py 345 234 &>> $expected_file
    ./${i} 345 234 &>> $output_file

	echo "test: 124 fse 1ed" | tee -a $expected_file $output_file
    ./solution.py ./${output}.py 124 fse 1ed &>> $expected_file
    ./${i} 124 fse 1ed &>> $output_file

    randomtest ${output} 1
    randomtest ${output} 2
    randomtest ${output} 3
    randomtest ${output} 4
    randomtest ${output} 5
    randomtest ${output} 6
    randomtest ${output} 7
    randomtest ${output} 8
    randomtest ${output} 9
    randomtest ${output} 10
    randomtest ${output} 11
    randomtest ${output} 12
    randomtest ${output} 13
    randomtest ${output} 14
    randomtest ${output} 15
    randomtest ${output} 16
    randomtest ${output} 17
    randomtest ${output} 18
    randomtest ${output} 19
    randomtest ${output} 20
    randomtest ${output} 21

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
