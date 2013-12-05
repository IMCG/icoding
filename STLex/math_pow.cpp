//pow
#include<iostream>
using namespace std;

int pow0(int x,int n)
{   
	int res=1;
	while(n>0)
	{
		res*=x;
		--n;
	}
	return res;
}
int pow1(int x,int n)
{
	if(n==0) return 1;
	if(n==1) return x;
    if(n%2==0)        //n&1
	   return pow1(x*x,n/2);
	else
	   return pow1(x*x,n/2)*x;
}
//res=x^1*x^4*x^8    1101=13;
int pow2(int x,int n)
{
	int res=1;
	while(n>0){
	 if(n&1) res*=x;
	 x*=x;
	 n>>=1;
	}
	return res;
}
	
int main()
{
	int n=2;
	int x=10;
	cout<<pow1(n,x)<<endl;
}