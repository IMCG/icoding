//比较三种情况大小
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n, m, a, b;
int main(){
	cin >> n >> m >> a >> b;
	bool ok = int(b / m) < a;
	int c = int(n / m);
	int num1 = n*a;
	int num2 = c*b + (n - c*m)*a;
	int cil = (n - 1) / m + 1;//取得上界
	cout << min(cil*b, min(num1, num2));
}

//2
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if (m*a <= b)
		cout << n*a << "\n";
	else//tricks
		cout << (n / m)*b + min((n%m)*a, b) << "\n";

	return 0;
}