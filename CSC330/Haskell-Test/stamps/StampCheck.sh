for i in {1..25}
do
    echo test $i
	input=$(printf "in%02d.txt" $i)
	output=$(printf "outputs/out%02d.txt" $i)
    ./Stamps $input $output

	expected=$(printf "out%02d.txt" $i)
    diff $expected $output
    echo ""
done
