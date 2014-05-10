//string & char
#include <cstdio>  
#include <cstring>  
#include <string>  
#pragma warning(disable:4996)
using namespace std;  
  
char str[100];  
string s;  
//字符串 和 char[] 很有区别
int main()  
{  
    //scanf("%s",str);  
    strcpy(str, "trans");  
    s = string(str); // char数组转string, 也可以string s(str);初始化  
    strcpy(str, s.c_str()); // string转char数组  
    //输出字符数组
    printf("%s", str);  
    return 0;  
}  