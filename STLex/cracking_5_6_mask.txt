#include<iostream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;

//Mask all odd bits with 10101010 in binary
int swapOddEvent(int x)
{
	return ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
}
void print_string(int x)
{
	/*string s=" ";
	while(x)
	{
		if(x%1)
			s="1"+s;			//have a problem
		else
			s="0"+s;
		x>>=1;
	}
	cout<<s<<endl;*/
	vector<int> coll;
	while(x)
	{
		if(x&1)
			coll.push_back(1);
		else
			coll.push_back(0);
		x>>=1;
	}
	while(!coll.empty())
	{
		cout<<coll.back();
		coll.pop_back();
	}
	cout<<endl;
	/*ostream_iterator<int,char> out(cout,"");
	copy(coll.begin(),coll.end(),out);*/
}
int main()
{
	int x=26;
	print_string(x);
	print_string(swapOddEvent(x));
	return 0;
}