//vector

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int A[7]={1,2,3,4,5,6,7};
	vector<int> coll(A,A+7);    //数组赋值

	vector<T> v1;				//保存类型T的对象，默认构造函数
	vector<T> v2(v1);
	vector<T> v3(n,i);          //vector<string> str(10,"hi!"); 10个string
	vector<T> v4(n);

	//对象操作
	/*v1.empty()   v1.size()  
		v1.push_back(data)
		v[n]   !=  >= operator*/

	//size 对象类似于 string 
	//下标操作不添加元素
	//添加元素只能coll.push_back();
	vector<int>::size_type i;
	for(i=0;i!=coll.size();++i)
		cout<<coll[i]<<" "<<endl;

	//迭代器
	//
	vector<int>::iterator pos;
	for(pos=coll.begin();pos!=coll.end();++pos)
		cout<<*pos<<" "<<endl;

	return 0;

	//function
	/*begin(),end(),rbegin(),rend();
	reserve(); Request a change in capacity 
	erase ,assign;*/
}