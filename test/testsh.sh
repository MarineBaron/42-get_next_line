
echo "TEST Multi fd"
echo "> parse samples directory"
filenames="";
for filename in `find ./samples -type f ! -name "*output*"`
	do
		filenames+=" "
		filenames+=$filename
	done
echo "> execution"
./test_gnl $filenames
echo "> diff"
for filename in `find ./samples -type f ! -name "*output*" | cut -d '/' -f3`
	do
		diff ./samples/$filename ./samples/output_$filename
	done
echo "> remove"
rm -Rf ./samples/output_*
