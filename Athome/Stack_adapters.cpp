/*容器配接器，对标准STL容器予以配接使之满足特殊需求
1.Stacks
2.Queues
3.Priority queues
*/
#include<stack>中class stack定义如下：
namespace std{
	template<class T,
			 class Container=deque<T>
		class stack;
}
//实际上stack只是很单纯的把各项操作转化为内部容器的对应调用。
//可以使用任何序列式容器支持stack，只要他们支持back(),push_back(),
//pop_back();选用deque移除元素时会释放内存。
Stacks的核心接口。push(),top(),pop();
class stack{
public:
  typedef typename _Sequence::value_type      value_type;
  typedef typename _Sequence::size_type       size_type;
  typedef          _Sequence                  container_type;

  typedef typename _Sequence::reference       reference;
  typedef typename _Sequence::const_reference const_reference;
protected:
  _Sequence c;
public:
  stack() : c() {}
  explicit stack(const _Sequence& __s) : c(__s) {}

  bool empty() const { return c.empty(); }
  size_type size() const { return c.size(); }
  reference top() { return c.back(); }
  const_reference top() const { return c.back(); }
  void push(const value_type& __x) { c.push_back(__x); }
  void pop() { c.pop_back(); }
};
//Queue 只需要支持push_back(),pop_front(),back(),front();
具体查看STL_QUEUE;
priority queue使用了STL heap算法。。


