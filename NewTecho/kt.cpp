//康托展开
#include <cstdio>  
const int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};///阶乘  
  
int KT(int s[], int n)  
{  
    int i, j, cnt, sum;  
    sum = 0;  
    for (i = 0; i < n; ++i)  
    {  
        cnt = 0;  
        for (j = i + 1; j < n; ++j)  
            if (s[j] < s[i]) ++cnt;  
        sum += cnt * fac[n - i - 1];  
    }  
    return sum;  
}  
  
int main()  
{  
    int a[] = {3, 5, 7, 4, 1, 2, 9, 6, 8};  
    printf("%d\n", 1 + KT(a, sizeof(a) / sizeof(*a))); ///1+98884  
}  
//全排列的解码

#include<cstdio>  
#include<cstring>  
const int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};///阶乘  
  
bool vis[10];  
  
///n为ans大小，k为全排列的编码  
void invKT(int ans[], int n, int k)  
{  
    int i, j, t;  
    memset(vis, 0, sizeof(vis));  
    --k;  
    for (i = 0; i < n; ++i)  
    {  
        t = k / fac[n - i - 1];  
        for (j = 1; j <= n; j++)  
            if (!vis[j])  
            {  
                if (t == 0) break;  
                --t;  
            }  
        ans[i] = j, vis[j] = true;  
        k %= fac[n - i - 1];///余数  
    }  
}  
  
int main()  
{  
    int a[10];  
    invKT(a, 5, 16);  
    for (int i = 0; i < 5; ++i)  
        printf("%d ", a[i]);///1 4 3 5 2  
}  