/*Author:xuesen
*@Date:12/27
*@C++STL Functors
*/
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
/*
@1.仿函数比一般函数更灵巧，因为它可以拥有状态。
@2.执行速度上，仿函数比函数指针更快。
@3.每个仿函数都有其型别，template参数来传递
*/
/*预定义的仿函数
negate<>		-param
plus<>			-  二元仿函数  		算数。。。。。。。。。。
minus<>			+
multiplies<>	*
divides<>		/
modulus<>		%
equal_to<> 	==		not_equal_to	!=
less<>	<		greater<>	>		比较。。。。。。。。。。
logical_not<>		!param
logical_and<>		&&
logical_or<>		||				逻辑。。。。。。。。。。
函数配接器(Adapters)：将仿函数和另一个仿函数（或某个值）结合起来的仿函数*/
void Print(vector<int> coll)
{
	for (auto c : coll)
		cout << c << " ";
	cout << endl;
}
int main()
{
	vector<int> coll(10);
	generate(coll.begin(), coll.end(), []{return rand() % 100; });
	Print(coll);
	/*组合型仿函数，检查某个 int?>42*/
	/*实际上bind2nd是将二元仿函数转换为一元仿函数
	表达式				效果
	bind1st(op,value)  op(value,param)
	bind2nd(op,value)  op(value,param)
	not1(op)		  !op(param)
	not2(op)		  !op(param1,param2)
	*/
	find_if(coll.begin(), coll.end(),
		bind2nd(greater<int>(), 42));
	/*通过函数配接器，我们把多个仿函数结合起来，形成强大的表达式
	：：一下返回集群中第一个偶数
	@函数指针不能满足STL对抽象性的要求，以及和Adapter搭配
	*/
	find_if(coll.begin(), coll.end(),
		not1(bind2nd(modulus<int>(), 2)));
	
	/*仿函数对象*/
	plus<int> plusobj;
	minus<int> minusobj;
	multiplies<int> multipliesobj;
	divides<int> dividesobj;
	modulus<int> modulusobj;
	negate<int> negateobj;

	cout << plusobj(3, 5) << endl;
	cout << "equal_to" << plus<int>()(3, 5) << endl;
	/*equal_to plus<int>() (3,5)*/
	cout << minusobj(3, 5) << endl;
	cout << multipliesobj(3, 5) << endl;
	cout << dividesobj(3, 5) << endl;
	cout << modulusobj(3, 5) << endl;
	cout << negateobj(3) << endl;
	
}