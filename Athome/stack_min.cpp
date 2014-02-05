//尹成blog.0203栈实现
/*用模板类实现栈*/
#include<iostream>
using namespace std;

template <typename T>
class stack{
public:
	stack(int len = 10);
	~stack();
	void push(T value);
	void pop();
	void clear();
	bool empty();
	T top();
	int size();
	T min();
private:
	int ntop;		//top元素
	int len;		//长度
	T *arr;			//栈数据

	int mtop;		//辅助栈，用来保存最小值
	int mlen;		//辅助栈长度
	T *marr;		//辅助栈数据
};
template <typename T>
stack<T>::stack(int len)
{
	if (len <= 0)
		return;
	this->len = len;		//初始化栈长度
	ntop = 0;			//空栈用0表示，那么顶端元素ntop-1
	arr = new T[len];	//申请栈空间

	/*辅助栈大小相同，每次弹入元素，都判断最小值*/
	mlen = len;
	/*将最小值入辅助栈，元素出栈时也和辅助栈比较，辅助栈的栈顶元素一直都是最小值*/
	mtop = 0;
	marr = new T[mlen];
}
template <typename T>
stack<T>::~stack()
{
	delete[]arr;
	delete[]marr;
}
template <typename T>
void stack<T>::push(T value)
{
	//判读是否有空间
	if (ntop == len)
		return;
	arr[ntop++] = value;
	
	//辅助栈用来保存最小值
	if (mtop == 0)
		marr[mtop++] = value;
	else if (value < marr[mtop - 1])
		marr[mtop++] = value;
}
template <typename T>
void stack<T>::pop()
{
	//判断空
	if (ntop == 0)
		return;
	//如果弹出的正好是最小值，那么把辅助栈先出栈
	if (arr[ntop - 1] == marr[mtop - 1])
		mtop--;
	//进行出栈
	ntop--;
}
template <typename T>
T stack<T>::top()
{
	if (ntop == 0)
		return NULL;
	return arr[ntop - 1];
}
template <typename T>
int stack<T>::size()
{
	return ntop;		//正好是ntop=size()
}
template <typename T>
void stack<T>::clear()
{
	//清空栈，ntop=0即可
	if (ntop == 0)
		return;
	ntop = 0;
	mtop = 0;
}
template <typename T>
T stack<T>::min()
{
	return marr[mtop - 1];
}
template <typename T>
bool stack<T>::empty()
{
	return ntop == 0;
}
//测试主函数
int main()
{
	stack<int> s;
	s.push(2);
	s.push(3);
	s.push(5);
	s.push(1);
	s.push(7);
	//s.pop();
	//s.pop();
	cout << s.size()<<endl;
	cout <<s.top()<<endl;
	cout << s.min()<<endl;

	system("pause");
	return 0;

}