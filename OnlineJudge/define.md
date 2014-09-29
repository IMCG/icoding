一些ACM常用的宏
============================

##1     
        #ifndef ONLINE_JUDGE 
            freopen("in.txt","r",stdin) ; 
        #endif
        主要是输入流重定向，方便本地测试
##2
        #define pow2(i) (1<<i)
        #define bit(i) (1<<i)
        #define isOdd(i) (i&1)
        #define isEven(i) (!(i&1))
        #define sz(i) i.size()
        #define REP(i, b, n) for (int i = b; i < n; i++)
        #define REPI(i, b, n) for (int i = b; i <= n; i++)
        #define rep(i, n) REP(i, 0, n)
        #define repi(i, n) REPI(i, 0, n)
        #define all(a) a.begin(),a.end()
        #define ABS(x) ((x) < 0 ? -(x) : (x)) 
        #define MAX( x, y ) ( ((x) > (y)) ? (x) : (y) ) 
        #define MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )

