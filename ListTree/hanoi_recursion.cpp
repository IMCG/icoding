#include<iostream>
using namespace std;

//The key of useing reursion is defining a function,don't care how to 
//execute,but you should understand the meaning.
void move(char x, int n, char z)
{
	cout << "move " << x <<" "<< n << "th " << z;
	cout << endl;
}
void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		move(x, 1, z);
	else{
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}
int main()
{
	int n = 3;
	hanoi(3, 'a', 'b', 'c');
	return 0;
}