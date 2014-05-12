#include <string>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int>Point;
//广度优先对于大数据超时

class PairGameEasy{
public:
	string bfs(Point &start,Point&end){
		queue<Point>q;
		queue<Point>next;
		q.push(start);

		while (!q.empty()){
			while (!q.empty()){
				Point t = q.front();
				q.pop();
				if (t == end)
					return "Able to generate";
				int a = t.first;
				int b = t.second;
				next.push(Point(a, a + b));
				next.push(Point(a + b, b));
			}
			swap(next, q);
		}
		return "Not able to generate";
	}
	string able(int a, int b, int c, int d){
		//预处理
		while (d > c && d%c == 0)
			d -= c;
		Point start(a, b);
		Point end(c, d);
		return bfs(start, end);
		//return "Able to generate";
		//return "Not able to generate";
	}
};
//math
string able(int a, int b, int c, int d)
{
    while (c > 0 && d > 0) {
        if ( c == a && d == b) {
            return "Able to generate";
        }
        if (c > d) {
            c -= d;
        } else {
            d -= c;
        }
    }
    return "Not able to generate";
}
