//Date:2014/2/27
//虽然是线性的但是用了哈希
#include <iostream>
using namespace std;
#define N 20
int HashMap[2 * N + 1];
void Sort(int arr[], int n)
{
	memset(HashMap, 0, sizeof(HashMap));
	for (int i = 0; i < n; i++){
		HashMap[arr[i]] = 1;
	}
	for (int i = 0; i < 2 * N + 1; i++){
		if (HashMap[i])
			cout << i << " ";
	}
}
//