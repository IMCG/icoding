/*http://www.careercup.com/question?id=6305783725686784
Given an array of integers (+ve and -ve), give a contiguous set of numbers 
that add to 1
Eg.	4 3 5 -3 -1 2 -3 10 2
Ans: 5 -3 -1 2 -3
*/
/*@@Anyway, one possible solution is to maintain a HashSet of partial sums. 
Partial sum is defined as follows:
partial_sum[0] = 0
partial_sum[i] = input[0] + input[1] + ... + input[i-1]
利用unorder_map<int,int>..
Notice that in order to find a sub-array whose elements sum to a given number k, 
it would suffice to find 0<=i<j<=input.length such that:
k = partial_sum[j] - partial_sum[i] = input[i] + input[i+1] + ... + input[j-1]
*/

