//任意两点间最短路径。Floyd Warshall algorithm
// 学习了
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int w[100][100];
// 默认路径0
int maxDifference(vector <string> isFriend, int d)
{
	int n = isFriend.size();
	int i, j, k, t;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			w[i][j] = isFriend[i][j] == 'Y';

	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (w[i][j] == 0 && w[i][k] != 0 && w[k][j] != 0)
					w[i][j] = w[i][k] + w[k][j];
				else if (w[i][j] > w[i][k] + w[k][j] && w[i][k] != 0 && w[k][j] != 0)
					w[i][j] = w[i][k] + w[k][j];

	for (i = 1; i < n; i++)
		if (w[0][i] == 0)
			return -1;

	t = -1;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			t = max(t, w[i][j]);

	return t * d;
}

//方法2  默认路径1000  good job。。
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)n-1;i>=0;i--)
#define all(v) v.begin(),v.end()

int dist[64][64];

class Egalitarianism {
public:
	int maxDifference(vector <string> isFriend, int d)
	{
		int n = isFriend.size();
		forn(i, n)
			forn(j, n)
			if (isFriend[i][j] == 'Y')
				dist[i][j] = 1;
			else
				dist[i][j] = 1000;
		forn(i, n)
			dist[i][i] = 0;
		forn(k, n)
			forn(i, n)
			forn(j, n)
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int res = 0;
		forn(i, n)
			forn(j, n)
			res = max(res, dist[i][j]);
		if (res == 1000)
			return -1;
		return res*d;
	}
};
