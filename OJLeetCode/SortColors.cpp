/*1.计数排序(counting sort)
 *2.设置前后两个index
 *3.利用快速排序partition的思想,先0,然后1.
*/
 class Solution{
 public:
 	void sortColors(int A[],int n){
 		int counts[3] = {0};
 		for (int i = 0; i < n; ++i)
 			counts[A[i]]++;
 		for(int i = 0,index = 0;i < 3;i++)
 			for(int j = 0;j < counts[i];j++)
 				A[index++] = i;
 	}
 };
 class Solution{
 public: 
 	void sortColors(int A[],int n){
 		//往中间走,注意循环中i变量的写法。
 		int red = 0,blue = n - 1;
 		for(int i = 0;i < blur+1;){
 			if(A[i]==0)
 				swap(A[i++],A[red++]);
 			else if(A[i]==2)
 				swap(A[i],A[blue--]);
 			else
 				i++;
 		}
 	}
 };
class Solution{
public:
	void sortColors(int A[],int n)
	{
		partition(partition(A,A+n,bind1st(equal_to<int>(),0)),A+n,
			bind1st(equal_to<int>(),1));
	}
};
//自己实现partition
template <typename ForwardIterator,typename UnaryPredicate>
ForwardIterator partition(ForwardIterator first,ForwardIterator last,
	UnaryPredicate pred){
	auto pos=first;
	for(;first!=last;++first)
		if(pred(*first))
			swap(*first,*pos++);
	return pos;
}