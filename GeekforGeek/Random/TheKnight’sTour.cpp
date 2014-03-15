//Backtracking | Set 1 (The Knight’s tour problem
#include <stdio.h>
#define N 8

/* A recursive utility function to solve Knight Tour problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N],
                int yMove[N])
{
   int k, next_x, next_y;
   if (movei == N*N)
       return true;
 
   /* Try all next moves from the current coordinate x, y */
   for (k = 0; k < 8; k++)
   {
       next_x = x + xMove[k];
       next_y = y + yMove[k];
       if (isSafe(next_x, next_y, sol))
       {
         sol[next_x][next_y] = movei;
         if (solveKTUtil(next_x, next_y, movei+1, sol, xMove, yMove))
             return true;
         else
             sol[next_x][next_y] = -1;// backtracking
       }
   }
 
   return false;
}
//check if i,j are valid indexs
int isSafe(int x,int y,int sol[N][N])
{
	if(x >= 0 && x < N && y >=0 && y < N && sol[x][y]==-1)
		return 1;
	return 0;
}
//print solution
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			printf(" %2d ", sol[i][j]);
		}
		printf("\n");
	}
}
//point function useing Backtracking
bool solveKT()
{
	int sol[N][N];
	//Init
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			sol[i][j] = -1;
		}
	}	
	/* xMove[] and yMove[] define next move of Knight.
       xMove[] is for next value of x coordinate
       yMove[] is for next value of y coordinate */
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    //Since the knight is init at first block
    sol[0][0] = 0;

    if(!solveKTUtil(0,0,1,sol,xMove,yMove)){
    	printf("solution does not exist");
    	return false;
    }
    else
    	printSolution(sol);
    return true;
}

int main()
{
	solveKT();
	getchar();
	return 0;
}