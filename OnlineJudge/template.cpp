#define mem(a) memset(a,0,sizeof(a))
#define memm(a) memset(a,-1,sizeof(a))
#define cpy(to, from) memcpy(to, from, sizeof(from))
#define ll long long 
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define all(a) a.begin(),a.end()

#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

#define Acc(a, n) (accumulate(a, a + (n), 0))
#define Min(a, n) (*min_element(a, a + (n)))
#define Max(a, n) (*max_element(a, a + (n)))
#define Minpos(a, n) (min_element(a, a + (n)) - a)
#define Maxpos(a, n) (max_element(a, a + (n)) - a)
#define Lowpos(a, n, x) (lower_bound(a, a + (n), x) - a)
#define Upppos(a, n, x) (upper_bound(a, a + (n), x) - a)
#define BS(a, n, x) binary_search(a, a + (n), x) /// 返回bool值
#define Range(a, n, x) equal_range(a, a + (n), x) /// 返回pair
#define Fpos(a, n, x) (find(a, a + (n), x) - a)

#define SI(a) scanf("%d", &a)
#define SII(a, b) scanf("%d%d", &a, &b)
#define SIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define SIIII(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define PI(a) printf("%d\n", a)
#define PII(a, b) printf("%d %d\n", a, b)
#define PIII(a, b, c) printf("%d %d %d\n", a, b, c)

#define Fin(f) freopen(f, "r", stdin) /// 请手动加.in
#define Fout(f) freopen(f, "w", stdout) /// 请手动加.out
#define random(m) ((rand() << 16 | rand()) % m) /// [0,m)之间的伪随机数
#define SR() srand((unsigned)time(NULL))
#define INF 0x3f3f3f3f

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int dirr[8][2] = {1, 0, 1, 1, 0, 1, -1, 1, -1, 0, -1, -1, 0, -1, 1, -1};
//const int knight_dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};

typedef std::pair<int, int> p2; 
typedef std::pair<std::pair<int, int>, int> p3;
typedef std::pair<int, std::pair<int, int> > pi3;