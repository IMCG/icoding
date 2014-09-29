//Uva 10763 Foreign Exchange 
#include <iostream>
#include <map>
using namespace std;
map<pair<int, int>, int> m;
bool solve(){
	for (auto& a : m)
		if (a.second)
			return false;
	return true;
}
int main()
{
	int n, a, b;
	//不能使用scanf_s
	while (scanf("%d",&n),n)
	{
		m.clear();
		while (n--)
		{
			scanf("%d%d", &a, &b);
			a < b ? ++m[make_pair(a, b)] : --m[make_pair(b, a)];
		}
		puts(solve() ? "YES" : "NO");
	}
	return 0;
}