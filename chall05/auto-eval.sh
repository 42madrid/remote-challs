#!/usr/bin/env zsh

# `brew install coreutils`
# to run `timeout` tests in cases of infinte loops

rm -rf traces
rm -rf tmp
mkdir traces
mkdir tmp

compiled=( )
not_compiled=( )

ok=( )
not_ok=( )

for i in *.c; do
    # skip main.c file
    if [[ $i == "main.c" ]]; then
        continue
    fi

    # do
    output=${i%.*}
    trace="traces/${output}_trace.txt"
    echo "Processing: $output"
    gcc -fsanitize=address main.c $i -o tmp/$output >> $trace 2>> $trace
    if [[ $? -eq 0 ]]; then
        echo "Compilation: OK" >> $trace
        compiled+=( $output )
    else
        echo "Compilation: KO" >> $trace
        not_compiled+=( $output )
    fi
done


echo -e "\tcompilation successful: $compiled"
echo -e "\tcompilation unsuccessful: $not_compiled"

for i in $compiled; do
    echo "Executing $i"
    trace="traces/${i}_trace.txt"
    timeout 5s ./tmp/$i >> $trace 2>> $trace
	ret=$?
    if [[ $ret -eq 0 ]]; then 
        echo "Exec: OK" >> $trace
        ok+=($i)
    else
		[[ $ret -eq 124 ]] && echo "Timed out after 5s" >> $trace
        echo "Exec: KO" >> $trace
        not_ok+=($i)
    fi
done

echo "OK: $ok"
echo "NOT_OK: $not_compiled $not_ok"
