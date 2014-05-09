//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class DeerInZooDivTwo{
public:
	vector<int>getminmax(int N, int K){
		int all = 2*N - K;
		int max1 = all / 2;
		int min1 = N - K > 0 ? N - K : 0;
		return{ min1, max1 };
	}
};
int main()
{
	DeerInZooDivTwo ss;
	int a, b;
	while (cin >> a >> b){
		vector<int>result = ss.getminmax(a, b);
		cout << result[0] << " " << result[1] << "\n";
	}
	return 0;

}