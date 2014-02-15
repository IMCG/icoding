/*given an 2D matrix M, is filled either using X or O, you need to find the region 
which is filled by O and surrounded by X 
and fill it with X. 

example 1: 

X X X X X 
X X O O X 
X X O O X 
O X X X X 

 Answer : 

X X X X X 
X X X X X 
X X X X X 
O X X X X

example 2: 

X X X X X 
X X O O X 
X X O O O 
O X X X X 

answer 2: 
X X X X X 
X X O O X 
X X O O O 
O X X X X
*/
/*The only logical clue I found is that if there is an "O" on the border, 
then any it along with all the connected "O"'s won't turn into "X". */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void fillWithY(vector<string>&A, int i, int j)
{
	if (i < 0 || i >= A.size() || j < 0 || j >= A[i].size() || A[i][j] != 'O')
		return;
	A[i][j] = 'Y';
	fillWithY(A, i - 1, j);//top
	fillWithY(A, i + 1, j);//bottom
	fillWithY(A, i, j - 1);//left
	fillWithY(A, i, j + 1);//right
}
int main()
{
	vector<string>A{ "XXXXX", "XXOOX", "XXOOO", "OXXXX" };
	if(A.size() < 2)
		return;
	//orgin
	for (size_t i = 0; i < A.size(); i++)
		cout << A[i] << endl;
	cout << endl;
	// first try to aborb '0's at the boundary and replace them with 'Y'
	for (size_t j = 0; j < A[0].size(); j++)
		fillWithY(A, 0, j);

	for (size_t j = 0; j < A.back().size(); j++)
		fillWithY(A, A.size() - 1, j);

	//for (int i = 1; i < A.size()-1; i++)
	for (size_t i = 0; i < A.size(); i++) {
		fillWithY(A, i, 0);
		fillWithY(A, i, A[i].size() - 1);
	}

	// rewrite internal 'O's with 'X', and restore 'Y's
	for (size_t i = 0; i < A.size(); i++) {
		for (size_t j = 0; j < A[i].size(); j++)
		if (A[i][j] == 'Y')
			A[i][j] = 'O';
		else if (A[i][j] == 'O')
			A[i][j] = 'X';
	}

	// shown me the result
	for (size_t i = 0; i < A.size(); i++)
		cout << A[i] << endl;
}