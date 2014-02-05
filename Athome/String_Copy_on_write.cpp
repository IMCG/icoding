/*Copy-On-Write
string类中必有一个私有成员，其是一个char*，
用户记录从堆上分配内存的地址，其在构造时分配内存，在析构时释放内存。*/
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	string str1 = "hello world";
	string str2 = str1;

	printf("Sharing the memory:\n");
	printf("\tstr1's address:%x\n", str1.c_str());
	printf("\tstr2's address:%x\n", str2.c_str());

	str1[1] = 'q';
	str2[1] = 'w';

	printf("After Copy-On-Write:\n");
	printf("\tstr1's address:%x\n", str1.c_str());
	printf("\tstr2's address:%x\n", str2.c_str());

	return 0;
}