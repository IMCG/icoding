#include<iostream>
#include<vector>
using namespace std;
void Print(vector<int>result)
{
	for (auto c : result)
		cout << c << "　";
	cout << endl;
}
int main()
{
	int A[] = {1,2,3,4,5};
	vector<int> coll(A, A + 5);
	Print(coll);

	const vector<int>::iterator iter = coll.begin();//T*const
	*iter = 10;
	//++iter;			非法，iter是const
	Print(coll);

	vector<int>::const_iterator citer = coll.begin();//const T*
	//*citer = 11;		非法，*citer是const
	++citer;
}
