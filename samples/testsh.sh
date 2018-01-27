echo ""
echo ">>>>>>>>>>>>>>>>"
cat -e ./samples/1line.txt
echo "<<<<<<<<<<<<<<<<"
./test_gnl ./samples/1line.txt | cat -e
echo ">>>>>>>>>>>>>>>>"
echo ""
echo ">>>>>>>>>>>>>>>>"
cat -e ./samples/2lines.txt
echo "<<<<<<<<<<<<<<<<"
./test_gnl ./samples/2lines.txt | cat -e
echo ">>>>>>>>>>>>>>>>"
echo ""
echo ">>>>>>>>>>>>>>>>"
cat -e ./samples/3lines.txt
echo "<<<<<<<<<<<<<<<<"
./test_gnl ./samples/3lines.txt | cat -e
echo ">>>>>>>>>>>>>>>>"
echo ""
echo ">>>>>>>>>>>>>>>>"
cat -e ./samples/1longline.txt
echo "<<<<<<<<<<<<<<<<"
./test_gnl ./samples/1longline.txt | cat -e
echo ">>>>>>>>>>>>>>>>"
echo ""
echo ">>>>>>>>>>>>>>>>"
cat -e ./samples/1longline_withendl.txt
echo "<<<<<<<<<<<<<<<<"
./test_gnl ./samples/1longline_withendl.txt | cat -e
echo ">>>>>>>>>>>>>>>>"
echo ""
echo ">>>>>>>>>>>>>>>>"
cat -e ./samples/3lines_oneempty.txt
echo "<<<<<<<<<<<<<<<<"
./test_gnl ./samples/3lines_oneempty.txt | cat -e
echo ">>>>>>>>>>>>>>>>"
echo ""
echo ">>>>>>>>>>>>>>>>"
cat -e ./samples/3lines_empty_at_end.txt
echo "<<<<<<<<<<<<<<<<"
./test_gnl ./samples/3lines_empty_at_end.txt | cat -e
echo ">>>>>>>>>>>>>>>>"