#include<iostream>
//构造100个对象。
using namespace std;
class Print{
public:
	static int i;
	Print()
	{
		i++;
		cout << i << endl;
	}
};
int Print::i = 0;
int main()
{
	const int N = 100;
	Print obj[N];
	return 0;
}

#include <stdio.h>
#define F4 "%d\n%d\n%d\n%d\n"
#define F20 F4 F4 F4 F4 F4
#define F100 F20 F20 F20 F20 F20
#define X4(y) , y, y + 1, y + 2, y + 3
#define X20(y) X4(y) X4(y + 4) X4(y + 8) X4(y + 12) X4(y + 16)
#define X100(y) X20(y) X20(y + 20) X20(y + 40) X20(y + 60) X20(y + 80)
int main() {
  printf(F100 X100(1));
  return 0;
}

#include<iostream>
using namespace std;
int i;
void b() { cout<<i++<<endl; }
void c() { b(); b(); b(); b(); b(); }
void a() { c(); c(); c(); c(); c(); }
int main()
{
    i=1;
    a(); a(); a(); a();
}


#include<stdio.h>
//The standard template metaprogram
template<int N>
struct X :X<N - 1>
{
	X(){ printf("%d\n", N); }
};
template<>
struct X<0> {};

int main()
{
	X<100>x;
	return 0;
}


//Using a static variable and an array
#include<stdio.h>

struct X{
	static int i;
	X(){ ++i; printf("%d\n", i); }
};
int X::i = 0;
int main()
{
	X arr[100];
	return 0;
}


#include<iostream>
#include<numeric>
#include<iterator>
#include<array>
using namespace std;

int main()
{
	array<int, 100>arr;
	iota(arr.begin(), arr.end(), 1);
	copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, "\n"));
}



void f(int n){
   printf("%d\n",n);
   f(n+1);
}

int main(){
   f(1);
}
//(Can be shortened to this if you run ./a.out with no extra params)
void main(int n) {
   printf("%d\n", n);
   main(n+1);
}


#include <iostream>
template<int N>
struct NumberGeneration{
  static void out(std::ostream& os)
  {
    NumberGeneration<N-1>::out(os);
    os << N << std::endl;
  }
};
template<>
struct NumberGeneration<1>{
  static void out(std::ostream& os)
  {
    os << 1 << std::endl;
  }
};
int main(){
   NumberGeneration<1000>::out(std::cout);
}