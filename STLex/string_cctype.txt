#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
	
	string str="HELLO WORLD";
	cout<<str<<endl;
	string::size_type i=0;		//×¢ÒâÀàÐÍ
	while(i!=str.size())
	{
		str[i]=tolower(str[i]); //toupper();
		i++;
	}

	cout<<str<<endl;
    return 0;
}