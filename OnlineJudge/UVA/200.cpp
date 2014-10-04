//拓扑排序
/*1.如何把字符存为整数  两种方法但是一个[0--25]  [1--26]
		直接减去-'A'
		对于大写可以 &31
//2.如何只遍历存在的字符，以及循环的方法。*/
/*copy字符串 
		strcpy(det,scr) 
		memcpy(dst,scr,sizeof(scr))   
  读取字符串scanf("%s",s)   gets(s);
  打印字符  printf("%c",c)  putchar(c);
		putchar(10) 换行
		*/
//AC
//200 Rare Order
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
//#include "algo.h"
using namespace std;
vector<int> G[30];
bool has[30], vis[30];
int ans[30], cnt;
void dfs(int i){
	vis[i] = true;
	for (auto& k : G[i])
		if (!vis[k])dfs(k);
	ans[cnt++] = i;
}
char first[30];
char now[30];
int main(){
	//freopen("E:\\in.txt", "r", stdin);
	scanf("%s", first);
	//如果只有一行的情况
	has[first[0]-'A'] = true;
	while (scanf("%s", now), strcmp(now, "#") != 0){
		for (int i = 0; i < (int)strlen(first) && i < (int)strlen(now); ++i){
			if (first[i] != now[i]){
				has[first[i] -'A'] = has[now[i] -'A'] = true;
				G[first[i] -'A'].push_back(now[i] -'A');
				break;
			}
		}
		strcpy(first, now);
	}
	for (int i = 0; i < 26; ++i)
		if (has[i] && !vis[i])dfs(i);
	for (int i = cnt - 1; i >= 0; --i)
		putchar(ans[i] + 'A');
	putchar(10);
	return 0;
}
//AC
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
vector<int> G[30];
bool has[30], vis[30];
int ans[30], cnt;
void dfs(int i){
	vis[i] = true;
	for (auto& k : G[i])
		if (!vis[k])dfs(k);
	ans[cnt++] = i;
}
char first[30];
char now[30];
int main(){
	
	scanf("%s", first);
	//如果只有一行字符的情况
	has[first[0] & 31] = true;
	while (scanf("%s", now), strcmp(now, "#") != 0){
		for (int i = 0; i < (int)strlen(first) && i < (int)strlen(now); ++i){
			if (first[i] != now[i]){
				has[first[i]&31] = has[now[i]&31] = true;
				G[first[i]&31].push_back(now[i]&31);
				break;
			}
		}
		strcpy(first, now);
	}
	for (int i = 1; i < 27; ++i)
		if (has[i] && !vis[i])dfs(i);
	for (int i = cnt - 1; i >= 0; --i)
		putchar(ans[i] + 'A' - 1);
	putchar(10);
	return 0;
}
