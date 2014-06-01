#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100;
int n, m;
vector<int>a(n);
int main()
{
	while (cin >> n >> m){
		while (n--){
			int t;
			cin >> t;
			a.push_back(t);
		}
		int b = 0;
		while (a.size()){
			int c = m;
			while (a.size()&&c >= a[0]){
				c -= a[0];
				a.erase(a.begin());
			}
			b+=1;
		}
		cout << b << "\n";
	}
}