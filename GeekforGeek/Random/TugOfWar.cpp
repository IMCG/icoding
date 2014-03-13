//Tug of War 拔河，diff最小
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
void print(vector<int>&a, vector<int>&b){
	for (auto& i : a){
		cout << i << " ";
	}
	cout << endl;
	for (auto& i : b){
		cout << i << " ";
	}
	cout << endl;
}
int sum(vector<int>&a){
	return accumulate(begin(a), end(a), 0);
}
void swap_(vector<int>&a, vector<int>&b){
	int sa = sum(a);
	int sb = sum(b);
	if (sa < sb)
		swap_(b, a);
	int diff = (sa - sb) / 2;
	if (diff == 0)return;

	int d = 0;
	int maxindex, minindex;
	for (size_t i = 0; i < a.size(); i++){
		for (size_t j = 0; j < b.size(); j++){
			int t = a[i] - b[j];
			if (t >= 0 && d <= diff&&t>d){
				d = t;
				maxindex = i;
				minindex = j;
			}
		}
	}
	if (d){
		swap(a[maxindex], b[minindex]);
		swap_(a, b);
	}
}
int main()
{
	vector<int>arr{ 23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4 };
	cout << "Sum: " << sum(arr) << endl;
	vector<int>a(arr.begin(), arr.begin() + arr.size() / 2);
	vector<int>b(arr.begin() + arr.size() / 2, arr.end());
	print(a, b);
	cout << "sum1: " << sum(a) << " " << sum(b) << endl;
	swap_(a, b);
	print(a, b);
	cout << "sum1: " << sum(a) << " " << sum(b);
	cout << endl;
}