//模板特化
#include <cstdio>

template <int n>
struct fib{
	long long int ans = 0;
	fib() {
		fib<n - 1> f1;
		fib<n - 2> f2;
		ans = f1.ans + f2.ans;
	}
};
template <> struct fib<2> { long long int ans = 1; };
template <> struct fib<1> { long long int ans = 1; };
int main()
{
	fib<45> f;
	std::printf("%lld", f.ans);
}