#include <vector>
using namespace std;

int selectGasStation(const vector<int> &a, const vector<int> &g) {
    int sum = 0, result = 0;
	int j = -1;
	const int m = a.size();
	for (int i = 0; i < m; ++i){
		sum += a[i] - g[i];
		result += a[i] - g[i];
		if (sum < 0){
			sum = 0;
			j = i;
		}
	}
	//result>=0
	return (result>=0) ? j + 1 : -1;
}