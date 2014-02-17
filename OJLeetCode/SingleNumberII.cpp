//Given an array of integers, every element appears three times 
//except for one. Find that single one.
/*ones---->到目前为止二进制1出现‘1’次的位。
 *twos---->到目前为止二进制1出现‘2’次的位。
 *当ones和twos同时为1时，消去。（threes）
 */
 class Solution{
 public:
 	int singleNumber(int A[],int n){
 		int ones=0,twos=0,threes=0;
 		for (int i = 0; i < n; ++i)
 		{
 			twos |= (ones & A[i]);
 			ones ^= A[i];
 			threes = ~(ones & twos);
 			ones &= threes;
 			twos &= threes;
 		}
 		return ones;
 	}
 };
 //Count the number of each bit
 class Solution{
 public:
 	int singleNumber(int A[],int n){
 		int res=0;
 		for (int i = 0; i < 32; ++i)
 		{
 			int count=0,bit=1<<i;
 			for (int j = 0; j < n; ++j)
 			{
 				if(A[j]&bit)
 					count++;
 			}
 			if(count%3!=0)
 				res|=bit;
 		}
 		return res;
 	}
 };