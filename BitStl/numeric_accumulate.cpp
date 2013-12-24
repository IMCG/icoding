//STL Algorithms
#include<iostream>
//#include<numeric>
#include<algorithm>
using namespace std;

template <class InputIterator, class T>
   T accumulate (InputIterator first, InputIterator last, T init)
{
  while (first!=last) {
    init = init + *first;  // or: init=binary_op(init,*first) for the binary_op version
    ++first;
  }
  return init;
}
const int N=9;
int main()
{
	int A[N]={1,2,3,4,5,6,7,8,9};
	cout<<accumulate(A,A+N,0.0)/N<<endl;
	//iterator
}