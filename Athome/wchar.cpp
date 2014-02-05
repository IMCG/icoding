//windows核心编程第二章
//声明Unicode字符和字符串的方法

//一个16位字符   UTF-16
wchar_t c=L'A';

//一个数组，包含99个16位字符，和一个16位的终止0
wchar_t szBuffer[100]=L'A String';
//L通知编译器字符串应当编译为一个Unicode字符串
//在这个简单的例子中，在每个ASCii字符之间都用一个0来间隔。

Windows头文件WinNT.h中
typedef char CHAR;//An 8-bit character
typedef wchar_t WCHAR;//An 16-bit character
一些处理字符和字符串指针。
//Pointer to 8-bit character
typedef CHAR* PCHAR;
typedef CHAR* PSTR;
typedef CONST CHAR* PCSTR;
//Pointer to 16-bit character
typedef WCHAR* PWCHAR;
typedef WCHAR* PWSTR;
typedef CONST WCHAR* PCWSTR;

//写代码时候，可以ANSI或Unicode字符/字符串都能通过编译。->宏
#ifdef UNICODE

typedef WCHAR TCHAR,*PTCHAR,PTSTR;
typedef CONST WCHAR* PCTSTR;
#define __TEXT(quote) quote//r_winnt

#define __TEXT(quote) L##quote

#else

typedef CHAR TCHAR,*PTCHAR,PTSTR;
typedef CONST CHAR* PCTSTR;
#define __TEXT(quote) quote

#endif

#define TEXT(quote) __TEXT(quote)

//如果定义了Unicode就是一个16位字符，否则就是一个8位字符

typedef char TCHAR;//WINDOWS数据结构。
TCHAR c=TEXT('a');
//.................
TCHAR szBuffer[100]=TEXT("A String");

//多用Strsafe.h中的安全函数，少用strlen & wcslen。

//2.7节推荐的字符和字符串处理方式
