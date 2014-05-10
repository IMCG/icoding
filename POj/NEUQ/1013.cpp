#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n != -1){
		int a = (int)pow(10, n);
		cout << a*(a + 1) / 2 << "\n";
	}
	return 0;
}