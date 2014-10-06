//TMP
#include "algo.h"
using namespace std;
//这个程序的阶乘运算发生在编译阶段！！
//Fac
template<int n>
struct Factor{
	enum{
		value=n*Factor<n-1>::value
	};
};
template<>
struct Factor < 0 > {
	enum{value=1};
};

//Fib
template<int N>
struct Fib{
	enum{
		value = Fib<N - 1>::value + Fib<N - 2>::value
	};
};
template<>
struct Fib < 1 > {
	enum{ value = 1 };
};
template<>
struct Fib < 0 > {
	enum{ value = 0 };
};

int main(){
	//pi(Factor<5>::value);
	//pi(Factor<10>::value);
	pi(Fib<10>::value);
}