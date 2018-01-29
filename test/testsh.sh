#!/bin/sh
for filename in `find ./samples -type f | cut -d '/' -f 3 | cut -d '.' -f 1`
do
	echo ""
	echo "------- UNIT TESTS $filename"
	echo ">>>>>>>>>>>>>>>> input file"
	cat -e "./samples/$filename.txt"
	echo "<<<<<<<<<<<<<<<< execution"
	./test_gnl "./samples/$filename.txt" | cat -e
	echo "<<<<<<<<<<<<<<<< output file"
	cat -e "./samples/output_$filename.txt"
	echo ">>>>>>>>>>>>>>>>"
done
#rm ./samples/output*

# echo ""
# echo "------- GLOBAL TESTS"
# echo "<<<<<<<<<<<<<<<< execution"
# ./test_gnl $global | cat -e
# for filename in `find ./samples -type f | cut -d '/' -f 3 | cut -d '.' -f 1`
# do
# 	echo ">>>>>>>>>>>>>>>> input file"
# 	cat -e "./samples/$filename.txt"
# 	echo "<<<<<<<<<<<<<<<< output file"
# 	cat -e "./samples/output_$filename.txt"
# 	echo ">>>>>>>>>>>>>>>>"
# done