#include<stdio.h>

void abc(char *s)
{
	if (s[0] == '\0')
		return;

	abc(s + 1);
	abc(s + 1);
	printf("%c ", s[0]);
}
int main()
{
	abc("abc");
	return 0;
}
//num = 2^len-1 每个字母打印的次数

#include<stdio.h>
int fun(int count)
{
	printf("%d\n", count);
	if (count < 3)
	{
		fun(fun(fun(++count)));
	}
	return count;
}

int main()
{
	fun(1);
	return 0;
}
 // output
 // 1
 // 2
 // 3
 // 3
 // 3
 // 3
 // 3