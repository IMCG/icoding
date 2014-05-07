// ColorfulRoad
//f[n]代表从此处到末端的花费。。
int getMin(string road)
{
	//gives us the next color in the cycle
	map<char,char> next = { {'R','G'}, {'G','B'}, {'B','R'} };
	const int INF = 1000000;
    int n = road.size();
    int f[n];
    //Base case: (i=n−1), then we already visited the last position.cost 0.
    f[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        // we assume the current cycle is: road[i] -> next(road[i]) -> ...
        f[i] = INF;
        // of all next steps, find the one with gives the minimum cost:
        for (int j = i + 1; j < n; j++) {
            if ( road[j] == next[road[i]] ) {
                f[i] = std::min( f[i], (j - i)*(j - i) + f[j] );
            }
        }
    }
    // If result is >= INF, case is invalid, return -1.
    return (f[0] >= INF) ? -1 : f[0];
}