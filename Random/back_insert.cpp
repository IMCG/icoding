/*back insert deque list string vector
 *front insert deque list注意范围
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
void print(vector<int>&result)
{
	for (auto& i : result){
		cout << i << " ";
	}
	cout << endl;
}
int main()
{
	vector<int>coll;
	//1@create back inserter for coll
	back_insert_iterator<vector<int>>iter(coll);
	//insert elements 
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;
	//2@
	back_inserter(coll) = 44;
	back_inserter(coll) = 55;
	print(coll);
	//necessary to expand size 
	coll.reserve(2 * coll.size());
	//确保足够大的空间
	copy(coll.begin(), coll.end(), back_inserter(coll));
	print(coll);
	return 0;
}