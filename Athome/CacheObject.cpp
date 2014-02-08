//More Effective C++ p95  --map object
#include<iostream>
#include<string>
#include<map>
using namespace std;
int findCubicleNumber(const string&employeeName)
{
	//定义一个 map(employee name,cubicle number) 用来做局部缓存（local cache)
	typedef map<string, int> CubicleMap;
	static CubicleMap cubes;

	//尝试在cache 中找出一笔记录,if 则用 iteration指向
	CubicleMap::iterator it = cubes.find(employeeName);

	//找不到，则添加
	if (it == cubes.end())
	{
		int cubicle = 0;
		//the result of looking up employeeNameps cubicle number in the database;
		cubes[employeeName] = cubicle;
		return cubicle;
	}
	else
	{
		return (*it).second;	//it->second;  
	}

}