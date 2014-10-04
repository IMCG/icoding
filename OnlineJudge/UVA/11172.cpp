//Relational Operators
//AC
#include <iostream>
//#pragma warning(disable:4996)
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("E:\\in.txt", "r", stdin);
	int t, a, b;
	cin >> t;
	while (t--){
		cin >> a >> b;
		puts(a >= b ? (a == b ? "=" : ">") : "<");
	}
	return 0;
}