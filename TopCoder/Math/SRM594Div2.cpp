//search each point(i,j)
//Straightforward and long to code
bool startingPoint(int n, int m, int i, int j)
{
    bool visited[n][m];
    int x = i, y = j;
    while (! visited[x][y]) { // While current cell was not visited before
        visited[x][y] = true; // Mark it as visited
        x = (x + 1) % n; // move to the next cell
        y = (y + 1) % m; 
    }
    //Are all cells visited?
    for (int a = 0 ; a < n; a ++) {
        for (int b = 0 ; b < n; b ++) {
            if ( ! visited[a][b] ) {
                return false;
            }
        }
    }
    return true;
}
 
string ableTo(int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            // Try (i,j):
            if (startingPoint(n,m, i,j)) {
                return "Possible";
            }
        }
    }
    // None of the seats functions as a good starting point.
    return "Impossible";
}
//Simplifying the solution
//以point(i,j)为开始的节点可以组成一个unique cycle
//也就是说如果存在,则point start位置是无关紧要的
// error....
struct point{
    int x;
    int y;
    point(int a, int b) :x(a), y(b){}
    //重载一下运算符
    bool operator<(const point &A)const{
        return this->x < A.x;
    }
};
string ableTo(int n, int m){
    point start(0, 0);
    set<point>visited;
    //int x = start.x;
    //int y = start.y;
    while (visited.count(start) == 0) {
        visited.insert(start);
        start.x = (start.x + 1) % n;
        start.y = (start.y + 1) % m;
    }
    //看是否有些点没在set中
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (visited.count(point(i, j)) == 0)
                return "Impossible";
        }
    }
    return "Possible";
}

//使用pair or tuple 
// typedef tuple<int, int> Point;
// make_pair()
// get<0>(name);
// get<1>(name);
string ableTo(int n, int m){
    typedef pair<int, int> P;
    set<P>visited;
    P start{ 0, 0 };
    while (visited.count(start) == 0) {
        visited.insert(start);
        start.first = (start.first + 1) % n;
        start.second = (start.second + 1) % m;
    }
    //看是否有些点没在set中
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (visited.count(make_pair(i,j)) == 0)
                return "Impossible";
        }
    }
    return "Possible";
}


//Even simple
//it is possible to visit all seats if and only if (gcd(n,m)=1), 
int gcd(int a, int b)
{
    return ( (b == 0) ? a : gcd(b, a % b) );
}
 
string ableTo(int n, int m)
{
    return ( (gcd(n,m) == 1) ? "Possible" : "Impossible" );
}
