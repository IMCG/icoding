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
int singleNumbeIIr(int A[], int n)
{
	int ones = 0, twos = 0, threes = 0;
	for (int i = 0; i < n; i++)
	{
		twos |= (ones&A[i]);
		ones ^= A[i];

		threes = ~(ones&twos);
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