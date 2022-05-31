COMPILER='./build/SysY'
TEST_PATH='./test'
make
passed=0
CE=0
WA=0
for source_file in $(ls $(find $TEST_PATH -name '*.c'))
do
	$COMPILER ${source_file%.*}.c > ${source_file%.*}.s
	if [ $? == 0 ];
	then
		arm-none-linux-gnueabihf-gcc ${source_file%.*}.s -L $TEST_PATH/sylib.a -o ${source_file%.*}.tmp -mcpu=cortex-a72 --static
		qemu-arm ${source_file%.*}.tmp
		result=$?
		answer=$(cat ${source_file%.*}.ans)
		if [ $result == $answer ];
		then
			printf "\e[32m%-20s testcase: %-30s (result: %-3d | answer: %3d).\e[0m\n" "[PASSED]" ${source_file%.*} $result $answer
			passed=$((passed + 1))
		else
			printf "\e[31m%-20s testcase: %-30s (result: %-3d | answer: %3d).\e[0m\n" "[WRONG ANSWER]" ${source_file%.*} $result $answer
			WA=$((WA + 1))
		fi
	else
		printf "\e[33m%-20s testcase: %-30s compilation failed.\e[0m\n" "[COMPILE ERROR]" ${source_file%.*}
		CE=$((CE + 1))
	fi
done
echo -e "\e[32mpassed: $passed/$((passed + WA + CE))          \e[31mWA: $WA/$((passed + WA + CE))          \e[33mCE: $CE/$((passed + WA + CE))\e\e[0m"
