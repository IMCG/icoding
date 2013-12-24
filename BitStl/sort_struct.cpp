//STL Algorithms
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
struct placeT{
	int x;
	int y;
};
bool ComparePlaces(placeT one,placeT two)
{
	if(one.x!=two.x)
		return one.x<two.x;
	return one.y<two.y;
}
const int N=9;
int main()
{
	/*int A[N]={1,3,3,4,4,3,7,3,9};
	vector<int> coll(A,A+N);
	for(auto c:coll)
		cout<<c<<" "; 
	cout<<endl;*/
	placeT one,two,three;
	one.x=3;
	one.y=3;
	two.x=2;
	two.y=4;
	three.x=2;
	three.y=2;
	vector<placeT> coll;
	coll.push_back(one);
	coll.push_back(two);
	coll.push_back(three);
	for(auto c:coll)
		cout<<c.x<<" "<<c.y<<" "<<endl;
	sort(coll.begin(),coll.end(),ComparePlaces);  //lambda

	for(auto c:coll)
		cout<<c.x<<" "<<c.y<<" "<<endl;
}