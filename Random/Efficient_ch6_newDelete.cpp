/*Author:xuesen
*@Date:12/27
*@Efficient C++ Ch6
*/
#include<iostream>
using namespace std;
/*全局内存管理器是通用的，因此代价高。
专用内存管理器闭全局内存管理器快一个数量级以上*/

/*一个辅助结构来链接空闲列表相邻元素*/
class NextOnFreeList{
public:
	NextOnFreeList *next;
};
/*空闲列表被生命为一个由NextOnFreeList元素组成的列表*/
class Rational{
public:
	Rational(int a = 0, int b = 1) :n(a), d(b){}

	inline void *operator new(size_t size);
	inline void operator delete(void *doomed, size_t size);

	static void newMemPool(){ expandTheFreeList(); }
	static void deleteMemPool();
private:
	static NextOnFreeList *freeList;  //Rational对象 的空闲链表

	static void expandTheFreeList();
	enum{EXPANSION_SIZE=32};

	int n;//分子
	int d;//分母
};
/*new()在空闲列表中分配一个Rational对象*/
inline void *Rational::operator new(size_t size)
{
	if (freeList == 0){
		expandTheFreeList();
	}

	NextOnFreeList*head = freeList;
	freeList = head->next;

	return head;
}
/*delete()把Rational对象直接添加到空闲列表头部，以返回一个Rational对象*/
inline void Rational::operator delete(void *doomed, size_t size)
{
	NextOnFreeList*head = static_cast<NextOnFreeList *> doomed;

	head->next = freeList;
	freeList = head;
}
/*Rational和NextOnFreeList之间的类型转换是危险的*/
void Rational::expandTheFreeList()
{
	//分配一个足够大的对象以包含下一个指针
	size_t size = (sizeof(Rational) > sizeof(NextOnFreeList*)) ? 
		sizeof(Rational) : sizeof(NextOnFreeList*);

	NextOnFreeList*runner =
		static_cast<NextOnFreeList*> new char[size];
	freeList = runner;
	for (int i = 0; i < EXPANSION_SIZE; i++)
	{
		runner->next =
			static_cast<NextOnFreeList*>new char[size];
		runner = runner->next;
	}
	runner->next = 0;
}
void Rational::deleteMemPool()
{
	NextOnFreeList*nextptr;
	for (nextptr = freeList; nextptr != nullptr; nextptr = freeList)
	{
		freeList = freeList->next;
		delete[]nextptr;
	}
}
NextOnFreeList*Rational::freeList = 0;
int main()
{
	Rational *array[1000];
	Rational::newMemPool();

	for (int j = 0; j < 500; j++)
	{
		for (int i = 0; i < 1000; i++)
		{
			array[i] = new Rational(i);
		}
		for ( i = 0; i < 1000; i++)
		{
			delete array[i];
		}
	}

	Rational::deleteMemPool();
}