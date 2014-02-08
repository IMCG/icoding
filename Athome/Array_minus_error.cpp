//数组差：通过交换元素，使数组差最小
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
void Print(vector<int>& v)
{
	for (auto& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}
int Sum(vector<int>& v)
{
	return accumulate(v.begin(), v.end(), 0);
}
void Swap(vector<int>&a,vector<int>&b)
{
	
	//swap(max_element(a.begin(),a.end()), min_element(b.begin(),b.end()));
}
void SwapArray(vector<int> &a, vector<int> &b)
{
	int cmp = INT_MAX;
	if (Sum(a) == Sum(b))
		return;
	//Sort(a, b);
	int tmp = Sum(a) - Sum(b);
	while (tmp<cmp)
	{
		cmp = tmp;
		cout <<"cmp="<< cmp << " ";
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
	
		swap(a[a.size() - 1], b[0]);
		if ((Sum(a) - Sum(b)) < 0)
		{
			swap(b[0], a[a.size() - 1]);
			return;
		}
		tmp = Sum(a) - Sum(b);
		cout <<"tmp="<< tmp << " \n";
	} 
	//cout << "cmp="<<cmp<<"\ttmp="<<tmp << endl;
	return;
}
int main()
{
	vector<int>a = { 100, 98, 99, 1, 2, 3 };
	vector<int>b = { 1, 2, 3, 4, 5, 40 };
	Print(a);
	Print(b);
	SwapArray(a, b);
	cout << "swapped..\n";
	Print(a);
	Print(b);
	return 0;
}