/*题目：文件属性管理程序
**能对文件大小保存目录，创建时间以及上一次访问时间的属性查询。
**程序要能够在图形用户界面下形象演示。
*/
#include<iostream>
using namespace std;
class Date{

};
class File_Attr{
public:
private:
	int File_size;
	Date Creat_time;
	Date PreVisit_time;
};