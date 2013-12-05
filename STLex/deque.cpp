#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	deque<string> coll;
	coll.assign(3,string("string"));
	coll.push_back("last string");
	coll.push_front("first string");
	copy(coll.begin(),coll.end(),ostream_iterator<string>                (cout,"\n"));
	cout<<endl;
	//remove
	coll.pop_back();
	coll.pop_front();
	for(int i=0;i<coll.size();++i)
	{
		coll[i]="another"+coll[i];
	}
	coll.resize(4,"resized string");
	copy(coll.begin(),coll.end(),
		ostream_iterator<string>(cout,"\n"));
}