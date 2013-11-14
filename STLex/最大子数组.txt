#include<iostream>
#include<vector>
using namespace std;
class solution{
public:
/*	int maxSubArray(int A[],int n)
	{
	int result=INT_MIN,f=0;
	for(int i=0;i<n;++i)
	{
		f=max(f+A[i],A[i]);
		result=max(result,f);
	}
	return result;
	}
*/
	int maxSubArray(int A[],int n)
	{
		int result=INT_MIN,f=A[0];
		for(int i=1;i<n;++i)
		{
			if(f<=0)
				f=A[i];
			else
				f+=A[i];
			if(f>result)
				result=f;
		}
		return result;
	}
};

int main()
{
	int A[]={-2,1,-3,4,-1,2,1,-5,4};
	solution s;
	cout<<s.maxSubArray(A,9)<<endl;
}