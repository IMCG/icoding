//http://www.careercup.com/question?id=15556758
/*There is an island which is represented by square matrix NxN. 
A person on the island is standing at any given co-ordinates (x,y). He can move in
any direction one step right, left, up, down on the island. If he steps outside the island, 
he dies. 

Let island is represented as (0,0) to (N-1,N-1) (i.e NxN matrix) & person is standing 
at given co-ordinates (x,y). He is allowed to move n steps on the island (along the matrix).
What is the probability that he is alive after he walks n steps on the island? 
*/
#include<iostream>
#include<vector>
using namespace std;
bool isDead(unsigned int N, int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return true;
	return false;
}
static unsigned int deadCount = 0;
static unsigned int overallCount = 0;
void computeAllPaths(int x, int y, int n, int N)
{
	if (isDead(N, x, y)){
		deadCount += 1;
		overallCount += 1;
	}
	else{
		if (n > 0)
		{
			computeAllPaths(x - 1, y, n - 1, N);
			computeAllPaths(x + 1, y, n - 1, N);
			computeAllPaths(x, y - 1, n - 1, N);
			computeAllPaths(x, y + 1, n - 1, N);
		}
		else
		{
			overallCount += 1;
		}
	}
}
float probablilityofalive(int x, int y, int n, int N)
{
	if (x >= 0 && x < N&&y >= 0 && y < N)
	{
		deadCount = 0;
		overallCount = 0;
		computeAllPaths(x, y, n, N);
		return (float)deadCount / (float)overallCount;
	}
	return 1.0;
}
int main()
{
	int x = 4, y = 4, n = 5, N = 6;
	printf("probability (x:%d, y:%d, N:%d, n:%d) = %f", x, y, N, n,	probablilityofalive(x, y, n, N));

	return 0;
}