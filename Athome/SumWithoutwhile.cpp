//不通过循环实现累加
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;
int main()
{
	int N = 0;
	cout << "Please input a integer:　";
	cin >> N;
	vector<int> a(N);
	int i = 1;
	generate(a.begin(), a.end(),
		[&](){
		return i++;
			});
	for each(int c in a)
	{
		cout << c << " ";
	}
	int sum=accumulate(a.begin(), a.end(), 0);
	cout << "\nsum="<<sum << endl;
}