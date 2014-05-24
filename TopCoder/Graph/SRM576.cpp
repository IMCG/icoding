/*@分别测试[1-49] 所以考虑binary_search
 *@可用bfs & dfs 因为不需要最小长度,所以用dfs	
 */
int w, h, L;
bool visited[50][50];
vector<string> level;

// A recursive implementation of a DFS.
void dfs(int i, int j) {
	if (visited[i][j]) {
		return;
	}
	visited[i][j] = true;
	//j条件选取的方法
	// Edge: horizontal move left
	if ((j > 0) && (level[i][j - 1] == 'X')) {
		dfs(i, j - 1);
	}
	// Edge: horizontal move right
	if ((j < w - 1) && (level[i][j + 1] == 'X')) {
		dfs(i, j + 1);
	}
	// Edges: vertical moves
	for (int y = 0; y < h; y++) {
		if (abs(y - i) <= L && (level[y][j] == 'X')) {
			dfs(y, j);
		}
	}
}

int shortestLadder(vector <string> level, int coinRow, int coinColumn)
{
	h = level.size(), w = level[0].size();
	this->level = level;
	// For each possible length:
	for (L = 0; L < 49; L++) {
		memset(visited, 0, sizeof(visited));
		// Call the DFS:
		dfs(h - 1, 0);
		if (visited[coinRow - 1][coinColumn - 1]) {
			// We could reach the coin, length is good enough.
			return L;
		}
	}
	// 49 is always a valid length:
	return 49;
}