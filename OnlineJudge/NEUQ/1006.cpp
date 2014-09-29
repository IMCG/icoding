#include <iostream>
using namespace std;
bool solve(int n){
	return n % 2 == 0 
		&& n % 3 == 0 
		&& n % 7 == 0;
}
int main()
{
	for (int i = 10; i <= 1000; ++i){
		if (solve(i))
			cout << i << "\n";
	}
	return 0;
}