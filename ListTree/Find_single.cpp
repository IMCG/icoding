#include<iostream>
using namespace std;
int singleNumber(int A[], int n) {
	int result = A[0];
	if (n == 1) return result;
	for (int i = 1; i < n; i++)
		result ^= A[i];

	return result;
}

//or  ^
int Hash[100];
int findSingle1(int A[],int n)
{
	for (int i = 0; i < n; i++)
		Hash[A[i]]++;
	for (int i = 0; i < 100;i++)
	{
		if (Hash[i] == 1)
			return i;
	}
}
//对于除出现一次之外的所有的整数，
//其二进制表示中每一位1出现的次数是3的整数倍，
//将所有这些1清零，剩下的就是最终的数。
//http://www.cnblogs.com/daijinqiao/p/3352893.html
int singleNumbeIIr(int A[], int n)
{
	int ones = 0, twos = 0, threes = 0;
	for (int i = 0; i < n; i++)
	{
		twos |= (ones&A[i]);//二进制‘1’，出现二次
		ones ^= A[i];		//二进制‘1’，出现一次

		threes = ~(ones&twos);//二进制‘1’，出现三次，~
		ones &= threes;
		twos &= threes;
	}
	return ones;
}
class Solution {
    public int singleNumber(int[] A) {
        int ones = 0, twos = 0;
        int t_ones, t_twos;
        
        for(int i: A){
            t_ones = ones;
            t_twos = twos;
            ones = (t_ones ^ i) & (~t_twos);
            twos = (t_ones & i) | (t_twos & (~i));
        }
        
        return ones;
    }
}
int main()
{
	int A[9] = {1,2,3,4,5,2,4,1,3};
	cout << singleNumber(A, 9);
}