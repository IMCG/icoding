/*1.只在构造函数里调用new char[],只在析构函数里调用delete[].
@ 2.C++面试中string类的一种写法
*/
#include<utility>
#include<string.h>
#include<vector>
using namespace std;
class String{
public:
	String() :data_(new char[1]){ *data_ = '\0'; }
	String(const char*str) 
		:data_(new char[strlen(str) + 1])
	{
		strcpy(data_, str);
	}
	String(const String&rhs)
		:data_(new char[rhs.size() + 1])
	{
		strcpy(data_, rhs.c_str());
	}
	~String()
	{
		delete[] data_;
	}
	String&operator=(String rhs)//yes ,pase-by-value
	{
		swap(rhs);
		return *this;
	}
	size_t size()const
	{
		return strlen(data_);
	}
	const char* c_str() const
	{
		return data_;
	}
	void swap(String&rhs)
	{
		std::swap(data_, rhs.data_);
	}
private:
	//私有成员
	char* data_;
};
//上述类，能实现下列的功能。
void foo(String x)
{
}

void bar(const String& x)
{
}

String baz()
{
	String ret("world");
	return ret;
}

int main()
{
	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s4 = baz();

	std::vector<String> svec;
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(baz());
	svec.push_back("good job");
}