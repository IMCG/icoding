//来自挑战程序设计书中，
//贪心算法。注意中间循环的秒用
#include <iostream>
#include <string>
using namespace std;
const int MAX_N = 2000;
int N;
char S[MAX_N + 1];
//再维护一个cnt用于格式的输出cnt%80?"":"\n";
void solve(){
	//剩余的字符串
	int a = 0, b = N - 1;
	while (a <= b){
		bool left = false;
		for (int i = 0; i + a <= b; ++i){
			if (S[a + i] < S[b - i]){
				left = true;
				break;
			}
			else if (S[a + i]>S[b - i]){
				left = false;
				break;
			}
		}
		left ? putchar(S[a++]) : putchar(S[b--]);
	}
	putchar('\n');
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i){
		//getchar()的妙处
		getchar();
		scanf("%c", &S[i]);
	}
	solve();
	return 0;
}
//这样就可以通过了，不是输入字符而是字符串。。。
int main()
{
	while (~scanf("%d", &N))
	{
		for (int i = 0; i<N; i++)
			scanf("%s", &S[i]);
		solve();
	}
	return 0;
}

