#include<iostream>
#include<list>
#include<algorithm>
#include<cstdlib>
using namespace std;
bool IsPrime(int number)
{   
	number=abs(number);
	if(number==0 || number==1)
		 return false;
	if(number%2==0)
		return false;
	
	for(int i=3;i<number/2;i+=2)
	{
		if(number%i==0)
			return false;
	}
	return true;
}
int main()
{
	list<int> coll;
	for(int i=24;i<=30;++i)
		coll.push_back(i);
	list<int>::iterator pos;
	pos=find_if(coll.begin(),coll.end(), IsPrime);
	if(pos!=coll.end())
	{
		cout<<*pos<<"is first prime"<<endl;
	}
	else{
		cout<<"no prime "<<endl;
	}
}