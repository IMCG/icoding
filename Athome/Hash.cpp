//哈希表的实现
#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;

template<typename T>
class Node{
public:
	T value;		//hash节点值
	Node<T>*next;	//冲突的下一个节点
	int index;		//打印
};
template<typename T>
class Hash
{
public:
	Hash();
	~Hash();
	bool insert(T value);
	bool deleteNode(T value);
	Node<T>*FindValue(T value);//搜索节点
	void Print();
private:
	Node<T>*HashArray[10];		//10个节点指针
};
template<typename T>
Hash<T>::Hash()
{
	HashArray[10] = new Node<T>[10];
	memset(HashArray, NULL, sizeof(Hash));
}
template<typename T>
Hash<T>::~Hash()
{
	delete[]HashArray;
}
template<typename T>
void Hash<T>::Print()
{
	Node<T>*node;
	for (int i = 0; i < 10; i++)
	{
		if (HashArray[i] == nullptr)
			continue;
		node = HashArray[i];
		while (node!=nullptr)
		{
			cout << node->value << ":" << node->index << " ";
			node = node->next;
		}
		cout << endl;
	}
}
//FindValue:首先通过value%10获得index
template<typename T>
Node<T> *Hash<T>::FindValue(T value)
{
	Node<T> *node;
	/* 先判断HashArray，如果是空，则不用搜索了 */
	if (HashArray == NULL)
	{
		return NULL;
	}

	/* 根据hash算法，这里我们简单对10取模，获取hash下标 */
	node = HashArray[value % 10];
	if (node == NULL)
	{
		return NULL;
	}

	/* 在对应坐标的冲突链表中搜索value */
	while (node)
	{
		if (node->value == value)
		{
			return node;
		}
		node = node->pNext;
	}
	return NULL;
}
template<typename T>
/* 插入数据 */
bool Hash<T>::insert(T value)
{
	Node<T> *node;
	/* 首先判断HashArray，如果为空，则无法插入了 */
	if (HashArray == NULL)
	{
		return false;
	}

	/* 根据hash算法获得hash index，并判断index是不是为空，
	如果为空，说明该index下还从来未有数据插入过，
	那么直接将该输入插入即可 */
	if (HashArray[value % 10] == NULL)     //判断头数组中有没有
	{
		/* 构造节点 */
		node = new Node<T>;
		node->value = value;
		node->index = 1;
		node->pNext = NULL;

		/* 直接插入即可，即赋值 */
		HashArray[value % 10] = node;
		return true;

	}

	/* 如果该index下不为空，那么说明冲突，也有可能该值以前就已经插入过，通过findvalue去查找下
	如果能找到说明该值已经在hash表中，index++表明该值被多次插入过 */
	if (FindValue(value) != NULL)
	{
		FindValue(value)->index++;
		return false;
	}

	/* 如果findValue失败，说明数据没有插入过，那么构造节点 */
	node = new Node<T>;    //头插法
	node->value = value;
	node->index = 1;

	/* 以下两句代码将新节点加入到冲突链表的头

	比如有一个冲突节点如下：
	-> 13 -> 23 -> NULL

	这时候加入了33，那么33的位置应该在
	-> 33 -> 13 -> 23 -> NULL
	*/
	node->pNext = HashArray[value % 10];
	HashArray[value % 10] = node;
	return true;

}

/*
删除节点
*/
template<typename T>
bool Hash<T>::deleteNode(T value)
{
	Node<T> *node;
	if (HashArray == NULL)
	{
		return false;
	}

	// 根据hash算法获取头数组，如果头数组没有，则表明该value不存在
	if (HashArray[value % 10] == NULL)     //判断头数组中有没有
	{
		return false;
	}

	/* 通过FindValue去搜索，看节点是否存在，如果不存在也不用删除了 */
	if (FindValue(value) != NULL)
	{
		/* 如果存在，那么通过hash算法，获取冲突链表头 */
		node = HashArray[value % 10];

		/* 如果链表头节点就是该value，则删除头节点 */
		if (node->value == value)
		{
			Node<T> *temp = node;
			node = node->pNext;
			HashArray[value % 10] = node;
			delete temp;
			return true;
		}

		/* 如果不是在冲突链表头，那么就在冲突链表中，循环的查找吧 */
		while (node->pNext != NULL)
		{
			// 当找到这个value时
			if (node->pNext->value == value)
			{
				// 将这个value对应的node在链表里删除
				Node<T> *temp = node->pNext;
				node->pNext = temp->pNext;
				delete temp;
				return true;
			}
			node = node->pNext;
		}
		return false;

	}
	return false;


}

/* 测试主函数 */
int main()
{
	Hash<int> h;
	h.insert(4);
	h.insert(34);
	h.insert(54);

	h.insert(35);
	h.insert(8);
	h.insert(22);
	h.insert(48);
	h.insert(9);

	h.insert(32);
	h.insert(2);
	h.insert(3);
	h.insert(54);
	h.insert(37);
	h.insert(8);
	h.insert(54);
	h.insert(6);
	h.insert(9);
	h.insert(12);
	h.insert(12);
	h.insert(23);

	h.insert(37);
	h.insert(48);
	h.insert(54);
	h.insert(66);
	h.insert(9);
	h.insert(12);

	h.Print();


	system("pause");
	return 0;
}

