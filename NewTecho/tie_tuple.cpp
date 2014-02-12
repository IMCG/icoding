/*tie()函数*/
#include<iostream>
#include<tuple>
using namespace std;
int main()
{
	int myint;
	char mychar;
	float myfloat;
	tuple<int, float, char>mytuple;
	mytuple = make_tuple(10, 2, 6, 'a');	//packing values into tuple

	//unpacking values into tuple
	//tie(myint,ignore,mychar)=mytuple; 不关联第二个元素
	tie(myint, myfloat, mychar) = mytuple;
	cout << "myint contains: " << myint << endl;
	cout << "mychar contains: " << mychar << endl;
	cout << "myfloat contains: " << myfloat << endl;

	get<0>(mytuple) = 100;		//修改tuple
	cout << "After asignment myint " << get<0>(mytuple) << endl;
	return 0;
}