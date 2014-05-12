//
#include "algostuff.h"
using namespace std;
#define ll long long 

//Cryptography
ll encrypt(vector<int>numbers){
	ll temp = accumulate(numbers.begin(), numbers.end(),1,
		multiplies<int>());
	ll add = 0;
	for (auto& a : numbers){
		add=max<ll>( temp / a,add);
	}
	return temp + add;
}
//那样其实无用了，增加最小的数字++
ll encrypt(vector<int>numbers){
	auto m = min_element(numbers.begin(), numbers.end());
	int index = distance(numbers.begin(), m);
	numbers[index]++;
	return (ll)accumulate(numbers.begin(), numbers.end(),1,
		multiplies<int>());
}
//
long long encrypt(vector <int> numbers) {
	int min_i = 0;
	for (int i = 0; i < int(numbers.size()); i++) {
		if (numbers[min_i] > numbers[i]) {
			min_i = i;
		}
	}
	numbers[min_i]++;
	long long p = 1;
	for (int i = 0; i < int(numbers.size()); i++) {
		p *= numbers[i];
	}
	return p;
}
int main()
{
	//数据太大。
	vector<int>number{ 1000, 999, 998, 997, 996, 995 };
	cout << encrypt(number) << "\n";
}