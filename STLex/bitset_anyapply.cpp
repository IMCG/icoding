//bitset
#include<iostream>
#include<bitset>
#include<cstddef>
using namespace std;

int main()
{
	//assign
	bitset<n> b;				//n位0
	bitset<n> b(u);				//unsigned long
	bitset<n> b(s);				//string 对象s的副本
	bitset<n> b(s,pos，n);       //s中pos开始n个副本

	//对象操作
	/* b.any() 是否存在置为1的二进制数?
	b.none()  不存在置为1的二进制数？
	b.count()  1的个数；
	b.size()   二进制个数；
	b[pos]     访问位置
	b.test[pos]    pos 是否为1
	b.set()    全置为1
	b.set[pos]   pos置1
	b.reset()  全置0
	b.reset[pos]  pos置0
	b.flip()    诸位取反
	b.flip[pos]  pos 取反*/

	bitset<32> bitvec;
	bool is_set=bitvec.any();     //false
	bool is_not_set=bitvec.none();//true

	//conut返回size_t  <cstddef>
	//size_t sz=bitvec.size();
	size_t bits_set=bitvec.count();//the number of 1

	//访问bitset中的位
	for(int index=0;i!=32;index+=2)
		bitvec[index]=1;
	cout<<"bitvec"<<bitvec<<endl;
}