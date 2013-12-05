#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	typedef int KeyType;
	typedef pair<const KeyType,string> Pair;
	typedef map<KeyType,string> MapCode;

	MapCode codes;

	codes.insert(Pair(415,"san Francisco"));
	codes.insert(Pair(510,"Oakland"));

	MapCode::iterator i;
	for(i=codes.begin();i!=codes.end();i++)
		cout<<i->first<<" "<<i->second<<endl;
}