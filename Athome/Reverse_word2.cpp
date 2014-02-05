#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
void Reverse(char *p)
{
	//一旦发现空格，到达首字母
	for (int i = strlen(p)-1; i>=0; i--)
	{
		if (*(p+i)==' ' ||i==0)
		{
			//保存空格的位置
			int tmp = i;
			if (i > 0)
				tmp = i + 1;
			//output
			while (*(p+tmp)!=' '&&*(p+tmp)!='\0')
			{
				cout << *(p + tmp++);
			}
			cout << " ";
		}
	}
}
int main()
{
	char *p = "my name is bob";
	Reverse(p);
	return 0;
}