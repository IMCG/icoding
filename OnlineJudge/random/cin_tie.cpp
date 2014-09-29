//tie是将两个stream绑定的函数，空参数的话返回当前的输出流指针
//cin绑定输出流默认绑定cout
// by default, cin is tied to cout, which means 
//that cout is flushed before any operation on cin
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ostream*prevstr;
	ofstream ofs;
	ofs.open("E:\\out.txt");

	cout << "tie example:\n";//直接输入到屏幕
	// 空参数调用返回默认的output stream，也就是cout
	*cin.tie() << "This is inserted into cout\n";

	// cin绑定ofs，返回原来的output stream
	prevstr = cin.tie(&ofs);
	*cin.tie() << "This is inserted into file\n";// ofs，输出到文件
	cin.tie(prevstr);//恢复

	ofs.close();
	//system("E:\\out.txt");
	return 0;
}
/*在默认的情况下cin绑定的是cout，每次执行 << 操作符的时候都要调用flush，
这样会增加IO负担。可以通过tie(0)（0表示NULL）来解除cin与cout的绑定，
进一步加快执行效率。
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);//0 to NULL
	//IO
}