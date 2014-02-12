/*tuple 元组定义了一个固定数目元素的容器，类型可以不同，是对pair的泛化
*/
#include<tuple>
#include<iostream>
#include<functional>
using namespace std;
int main()
{
	//创建元组   get<>()访问元素
	auto t1 = make_tuple(10, "Test", 3, 14);
	cout << "The value of t1 is"
		<< " (" << get<0>(t1) << "," << get<1>(t1)
		<< "," << get<2>(t1) << ")\n";

	int n = 1;
	auto t2 = make_tuple(ref(n), n);//ref 表示引用。
	n = 7;
	cout << "The value of t2 is"
		<< " (" << get<0>(t2) << "," << get<1>(t2) << ")\n";
}