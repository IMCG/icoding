/*Author:xuesen
*@Date:2014/1/2
*@Effective_30 Inline
*/
#include<iostream>
using namespace std;
/*inline只是对编译器的一个申请，不是强制命令。可以隐喻提出，也可以明确提出*/
class Person{
public:
	...
	int age()const{return theAge;}		//一个隐喻inline申请。age被定义于class内
private:
	int theAge;
};
template<typename T>
inline const T& max(cosnt T&a,const T&b)
{
	return a<b?b:a;						//明确申请inline。
}
/*inline是个申请，编译器可加以落空。大部分编译器拒绝将太复杂的函数inlining.而所有对
virtual函数的调用也会使inline落空。virtual意味着“等待，直到运行期才确定调用那个函数”*/
