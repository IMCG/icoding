//A Police Recruits
#include <iostream>
using namespace std;

int solve(vector<int> &t){
	int s=0,n=0;
	for(auto&i:t){
		s+=i;
		if(s<0){
			s=0;
			n++;
		}
	}
	return n;
}
int main()
{
	int n;
	cin >> n;
	int officer = 0;
	int count = 0;
	int num;
	while(n--){
		cin>>num;
		if(num==-1){
			if(officer > 0)officer--;
			else count++;	
		}else{
			officer += num;
		}
	}
	cout<<count;
	return 0;
}

//B Prison Transfer
//维护一个<=t 的cut计数器
int ans = 0,cnt = 0;
int n,t,c;
scanf_s("%d%d%d",&n,&t,&c);
while(n--){
	scanf("%d",&val);
	if(val <= t)
		cnt++;
	else
		cnt = 0;
	if(cnt >= c) ++ans;
}
printf("%d",ans);

//C Checkposts
//Graphs 强连通分量...by ipqhjjybj

/*http://blog.sina.com.cn/s/blog_a2e4b3970101anak.html
 *https://www.byvoid.com/zhs/blog/scc-tarjan
 *http://blog.csdn.net/dellaserss/article/details/8267192
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MOD = (int)(1e9 + 7);
const int N = 222222;
int n, m, cc = 1;
long long cnt = 1, ans;
int a[N], dns[N], low[N], sta[N], fro;
vector<int> vec[N];
void dfs(int u){
	int minc = dns[u] = low[u] = ++cc;
	sta[fro++] = u;
	int w;
	for (int i = 0; i < (int)vec[u].size(); i++){
		if (!dns[w = vec[u][i]])
			dfs(w);
		if (low[w]<minc)minc = low[w];
	}
	if (minc<low[u]){
		low[u] = minc; return;
	}
	int tc = 0, min_a = 0x3f3f3f3f;
	do{
		low[w = sta[--fro]] = n + 1;
		if (a[w] < min_a){ min_a = a[w]; tc = 1; }
		else if (a[w] == min_a) tc++;
	} while (u != w);
	ans += min_a;
	cnt = (long long)cnt * tc % MOD;
}
int main(){
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf_s("%d", a + i);
	scanf_s("%d", &m);
	for (int i = 0, a, b; i < m; i++){
		scanf_s("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	for (int i = 1; i <= n; i++){
		if (!dns[i])
			dfs(i);
	}
	cout << ans << " " << cnt << endl;
	return 0;
}
//Tarjan 算法
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 10010

int n;
vector<int> g[maxn];
int Bcnt; /// 强连通分量的个数；  
int Top; /// 栈顶；  
int Index; /// 时间戳；  
int low[maxn], dfn[maxn];
int belong[maxn], stack[maxn];
bool instack[maxn];

void Init_tarjan(){
	Bcnt = Top = Index = 0;
	for (int i = 1; i <= n; ++i)low[i] = dfn[i] = 0;
}
void Tarjan(int u){
	stack[Top++] = u;
	instack[u] = 1;
	low[u] = dfn[u] = ++Index;
	for (int i = 0; i < (int)g[u].size(); ++i){
		int v = g[u][v];
		if (!dfn[v]){
			Tarjan(v);
			low[u] = min(low[v], low[u]);
		}
		else if (instack[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]){
		++Bcnt;
		int v;
		do{
			v = stack[--Top];
			instack[v] = 0;
			belong[v] = Bcnt;
		} while (u != v);
	}
}
int main()
{
	int m;
	while (cin >> n >> m, n + m){
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		while (m--){
			int x, y;
			scanf_s("%d%d", x, y);
			g[x].push_back(y);
		}
		Init_tarjan();
		for (int i = 1; i <= n; ++i){
			if (!dfn[i])
				Tarjan(i);
		}
		puts(Bcnt == 1 ? "Yes" : "No");
	}
}
//22
void tarjan(int i)
{
    int j;
    DFN[i]=LOW[i]=++Dindex;
    instack[i]=true;
    Stap[++Stop]=i;
    for (edge *e=V[i];e;e=e->next)
    {
        j=e->t;
        if (!DFN[j])
        {
            tarjan(j);
            if (LOW[j]<LOW[i])
                LOW[i]=LOW[j];
        }
        else if (instack[j] && DFN[j]<LOW[i])
            LOW[i]=DFN[j];
    }
    if (DFN[i]==LOW[i])
    {
        Bcnt++;
        do
        {
            j=Stap[Stop--];
            instack[j]=false;
            Belong[j]=Bcnt;
        }
        while (j!=i);
    }
}
void solve()
{
    int i;
    Stop=Bcnt=Dindex=0;
    memset(DFN,0,sizeof(DFN));
    for (i=1;i<=N;i++)
        if (!DFN[i])
            tarjan(i);
}
//...

//Kosaraju算法 两边dfs遍历
#include "iostream"
#include "iomanip"
#include "cstdio"
#include "cmath"
#include "cstring"
#include "algorithm"
using namespace std;

//************************
const int maxn=10010;
const int maxm=10010;
int n,m;

int len=1;
int star[maxn];
int et[maxm];
int v[maxm];
int next[maxm];

int q[maxn],tail;
bool used[maxn];
bool flag;
//************************
void addedge(int p,int qs,int qt,int qv)
{
    et[p]=qt;
    v[p]=qv;
    next[p]=star[qs];
    star[qs]=p;
}
//************************
void init()
{
   int i,qhs,qht;
   scanf("%d%d",&n,&m);
   for(i=1;i<=m;i++)
   {
      scanf("%d%d",&qhs,&qht);
      addedge(++len,qhs,qht,0);
      addedge(++len,qht,qhs,1);
   }
   tail=0;
}
void dfs0(int x)
{
 
  int j;
  int ns,nv,nt;
  if(used[x]) return;
  used[x]=true;
  ns=x;
  for(j=star[ns];j;j=next[j])
  {
      nt=et[j]; nv=v[j];
      if(nv) continue;
      dfs0(nt);
  }
  q[++tail]=x;
}
void dfs1(int x)
{
  int j;
  int ns,nv,nt;
  if(used[x]) return;
  flag=true;
  used[x]=1;
  ns=x;
  for(j=star[ns];j;j=next[j])
  {
      nt=et[j]; nv=v[j];
      if(!nv) continue;
      dfs1(nt);
  }
  printf("%d ",x);
}
//************************
int main()
{
   int k;
   init();
   memset(used,0,sizeof(used));
   for(k=1;k<=n;k++) dfs0(k);
   memset(used,0,sizeof(used));
   while(tail)
   {
      flag=false;
      dfs1(q[tail]);
      tail--;
      if(flag) printf("\n");
   };
   return 0;
}


//E.Police Patrol
//要计算路线和值，我们可以换个思路
//来累加——不按时间顺序累加，而是按这段路重复走的次数累加：
//输入已经保证是有序的
//@
ll ans = 0LL;
for (int i = 0, j = n - 1; i < j; i += m, j -= m) ans += (ll)(a[j] - a[i]);
printf("%I64d\n", ans << 1LL);
//1
#include <stdio.h>
long long a[1000005], n, m, i, dis;
int main(){
    for(scanf("%I64d%I64d", &n, &m), i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    for(i = 1; i + i - 1 <= n; i += m) dis += a[n - i + 1] - a[i];
    printf("%I64d\n", dis << 1);
    return 0;
}
//2
#include<cstdio>
using namespace std;

int a[1000005],n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long ans=0;
    for(int i=1,j=n;i<j;i+=m,j-=m)
        ans+=a[j]-a[i];
    ans*=2;
    printf("%I64d\n",ans);
    return 0;
}