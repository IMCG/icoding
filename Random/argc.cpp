#include <iostream>
/*
* argv[ ]: 字符串数组，用来存放指向你的字符串参数的指针数组，每一个元素指向一个参数
argv[0] 指向程序运行的全路径名
argv[1] 指向在DOS命令行中执行程序名后的第一个字符串
argv[2] 指向执行程序名后的第二个字符串
*/
int main(int argc, char** argv) {
	std::cout << "Have " << argc << " arguments:" << std::endl;
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}
}