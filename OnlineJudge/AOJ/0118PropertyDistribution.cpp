//深度优先
//x,y具体指代什么自己判断
#include <iostream>
using namespace std;
#define MAX_W 100
#define MAX_H 100
char farm[MAX_W][MAX_H];
int W, H;
const int direction[4][2] = {
	{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
void dfs(const int&x, const int &y, const char tree){
	farm[x][y] = 'x';
	for (int i = 0; i < 4; ++i){
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (nx >= 0 && nx < W&&ny >= 0 && ny < H&&farm[nx][ny] == tree)
			dfs(nx, ny, tree);
	}
}
int main()
{
	while (cin >> H >> W, W>0){
		int res = 0;
		int x, y;
		for (y = 0; y < H; y++){
			for (x = 0; x < W; x++){
				cin >> farm[x][y];
			}
		}
		for (y = 0; y < H; y++){
			for (x = 0; x < W; x++){
				if (farm[x][y] != 'x')
				{
					dfs(x, y, farm[x][y]);
					++res;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
//2
#include <iostream>
using namespace std;

int h, w;
char map[100][100];
int ans;

bool safe(int x, int y){
    return (0 <= x && 0 <= y && x < h && y < w);
}

void solve(char c, int x, int y){
    map[x][y] = '?';
    if (map[x+1][y] == c && safe(x+1, y)) solve(c, x+1, y);
    if (map[x-1][y] == c && safe(x-1, y)) solve(c, x-1, y);
    if (map[x][y+1] == c && safe(x, y+1)) solve(c, x, y+1);
    if (map[x][y-1] == c && safe(x, y-1)) solve(c, x, y-1);
    return;
}

int main(){
    while (1){
	cin >> h >> w;
	if (h == 0 && w == 0) break;

	ans = 0;
	for (int i = 0; i < h; i++){
	    for (int j = 0; j < w; j++){
		cin >> map[i][j];
	    }
	}

	for (int i = 0; i < h; i++){
	    for (int j = 0; j < w; j++){
		if (map[i][j] != '?'){
		    ans++;
		    solve(map[i][j], i, j);
		}
	    }
	}

	cout << ans << endl;
    }
}
//广度优先
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

char gy[110][110];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int vis[110][110];
int h,w;

struct node
{
    int x,y;
}a;
bool ok(int x,int y)
{
    if(x>=0 && x<h && y>=0 && y<w)
        return true;
    return false;
}
void bfs(int x,int y,char c)
{
    a.x = x;
    a.y = y;
    queue<node> q;
    q.push(a);

    node cur,next;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            next.x = cur.x+dx[i];
            next.y = cur.y+dy[i];
            if(ok(next.x,next.y) && !vis[next.x][next.y] && gy[next.x][next.y]== gy[cur.x][cur.y])
            {
                vis[next.x][next.y]=true;
                q.push(next);
            }
        }
    }
}

int solve()
{
    int cnt=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(!vis[i][j])
            {
                bfs(i,j,gy[i][j]);
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
}

int main()
{
    while(scanf("%d%d",&h,&w)!=EOF)
    {
        if(h==0 && w==0)
            break;
        memset(gy,0,sizeof(gy));
        memset(vis,0,sizeof(vis));

        for(int i=0;i<h;i++)
            scanf("%s",gy[i]);
        solve();
    }
    return 0;
}