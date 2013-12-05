#include<iostream>
using namespace std;
bool isEven(int n)
{
	return !(n&1);
}
int gcd(int m,int n)
{
	return n==0?m:gcd(n,m%n);
}
int gcd1(int m,int n)
{
	if(m<n)
		return gcd1(n,m);
	else if(n==0) return m;
	else 
		return gcd1(m-n,n);
}
int gcd2(int m,int n)
{
	int c=1;
	while(m!=0 && n!=0)
	{
		//if(m<n) return gcd2(n,m);
		if(isEven(m)&&isEven(n))
		{
			m>>1;
			n>>1;
			c<<1;
			//return 2*gcd2(m>>1,n>>1);
		}
		else if(isEven(m)&&!isEven(n))
		{
			m>>1;
		}
		else if(isEven(n)&&!isEven(m))
		{
			n>>1;
		}
		else if(!isEven(m)&&!isEven(n))
		{
			int m1=m;
			int n1=n;
			m=abs(m-n);
			n=min(m1,n1);
		}
		return c*n;
	}
}
int main()
{
	
}