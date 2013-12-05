#include<iostream>
#include<cstdio>
#include<cassert>
using namespace std;

bool IsPrime(int n)
{
	if(n<0 || n==1) return 0;
	else if(n%2==0) return 0;
	else 
	{
		for(int i=3;i<n/2;i+=2)
		{
			if(n%i==0) return 0;
		}
		return 1;
	}
}
void put_isprime_add(int n)
{
	if(IsPrime(n))
		cout<<"error"<<endl;
	else
	{
		int m=3;
		for( ; m<n/2;m+=2)
		{
			if(IsPrime(m) && IsPrime(n-m))
			{
				cout<<n<<"="<<m<<"+"<<n-m<<endl;
				break;
			}
		}
	}
}
int main()
{
	int text_n;
	while(cin>>text_n)
	{
		cout<<"?isprime"<<" "<<IsPrime(text_n)<<endl;
		put_isprime_add(text_n);
	}

	return 0;
}