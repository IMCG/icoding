//破解二进制
//http://www.hankcs.com/program/tokyodaigaku.html/2/
#include <iostream>
#include <bitset>
#pragma warning(disable:4996)
using namespace std;
///////////////////////////////////////////////////////
//1
void a(){
	bitset<4>foo;
	foo[1] = 1;			//0010
	foo[2] = foo[1];	//0110
	cout << "foo:　"<<foo << "\n";
}
//2
// bitset::flip 翻转
#include <iostream>       // std::cout
#include <string>         // std::string
#include <bitset>         // std::bitset

int main ()
{
  std::bitset<4> foo (std::string("0001"));

  std::cout << foo.flip(2) << '\n';     // 0101
  std::cout << foo.flip() << '\n';      // 1010

  return 0;
}
int main()
{
	freopen("E:\\in.txt", "r", stdin);
	freopen("E:\\out.txt", "w", stdout);
	bitset<8>bit8;
	while (cin >> bit8){
		cout << static_cast<char>(bit8.to_ulong());
	}
	fclose(stdin);
	fclose(stdout);
	system("E:\\out.txt");
	return 0;
}