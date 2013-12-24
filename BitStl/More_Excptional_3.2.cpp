#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

template<typename T>
class GreaterThan{
public:
	GreaterThan( T value):value_(value){}
	bool operator()(const T& t) const
	{
		return t>value_;
	}
private:
	const T & value_;
};
bool IsAnyGreaterFive( vector<int> & v)
{
	return find_if(v.begin(),v.end(),GreaterThan<int>(5))!=v.end();
}
int main()
{

}