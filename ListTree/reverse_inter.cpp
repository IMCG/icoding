#include<iostream>
using namespace std;
void reverse_num(int n)
{
	if(n<0)
	{
		n=-n;
	 	cout<<"-";
	}
   while(n)
   {
   	 cout<<n%10;
   	 n/=10;
   }
}
bool isPalindrome(int x)
{
	if (x < 0)return false;
	int d = 1;//divisor
	while (x / d >= 10) d *= 10;

	while (x>0){
		int q = x / d;
		int r = x % 10;
		if (q != r)return false;
		x = x%d / 10;
		d /= 100;
	}
	return true;
}

//a recursive solution
bool isPalindrome(int x, int &y) {
  if (x < 0) return false;
  if (x == 0) return true;
  if (isPalindrome(x/10, y) && (x%10 == y%10)) {
    y /= 10;
    return true;
  } else {
    return false;
  }
}
bool isPalindrome(int x) {
  return isPalindrome(x, x);
}

class Solution{
public:
  int reverse(int x)
  {
  	int r=0;
  	for(;x;x/=10)
  	{
	  	r=r*10+x%10;
	  }
	  return r;
  }	
};
int main()
{
	int n;
	cin>>n;
	Solution s;
	int num=s.reverse(n);
   cout<<num;
}