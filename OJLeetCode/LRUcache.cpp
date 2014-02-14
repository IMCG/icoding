/*Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.
*/
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
/*list.splice  -->从参数列表中删除元素,并将其插入到目标表

为了查找，插入，删除都有较高的性能，我们使用双端列表(std::list),和一个哈希表
（std::unorderd_map)
	.哈希表保存每个节点的地址，可以基本保证O(1)时间内查找结点
	.双向列表插入，删除效率高，单向列表插入和删除时，需要找到前驱结点
具体实现：
	。越靠近列表头部，表示节点上次访问距离现在时间较短，尾部节点表示LRU
	。访问节点时，如果节点存在，则交换到头部，并更新map
	。插入节点时，如果size>capacity.删除最后节点，并删除map对应项。然后插入节点到头部。
*/
class LRUCache{
private:
	struct CacheNode{
		int key;
		int value;
		CacheNode(int k, int v) :key(k), value(v){}
	};
	list<CacheNode> cacheList;
	unordered_map<int, list<CacheNode>::iterator> cacheMap;
	int capacity;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (cacheMap.find(key) == cacheMap.end())
			return -1;
		//把当前访问的节点移到链表的头部，并且更新map中该节点的地址
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}

	void set(int key, int value) {
		if (cacheMap.find(key) == cacheMap.end())
		{
			if (cacheList.size() == capacity)
			{
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			//插入新节点到头部，并在map中添加索引
			cacheList.push_front(CacheNode(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else
		{
			//更新
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
};
int main()
{
	LRUCache text(5);
	text.set(2, 1);
	text.set(2, 7);
	text.set(3, 9);
	text.set(4, 2);
	text.set(5, 0);
	text.set(6, 9);
	text.set(7, 3);
	cout << text.get(3) << endl;
}