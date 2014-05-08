//A.Sereja and Mugs
#include <cstdio>

using namespace std;
//自己拿最大的。
int n,s,a,t,m;
string solve(vector<int> a,int s){
	int sum = accumulate(a.begin(), a.end(),0);
	int ma = *max_element(a.begin(), a.end());
	return sum - ma <= s?"YES":"NO";
}
int main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    scanf("%d %d",&n,&s);
    while (n--)
    {
        scanf("%d",&a);
        t+=a;
        if (m<a) m=a;
    }
    puts(t-m<=s?"YES":"NO");
    return 0;
}
