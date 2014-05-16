//LittleElephantAndDouble
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//是不是2的幂。不完整。没判断0.。。
int isPower(int n){
	return !((n)&(n - 1));
}
string getAnswer(vector<int>A){
	sort(A.begin(), A.end());
	unique(A.begin(), A.end());
	int len = A.size();
	if (len == 1)
		return "YES";
	for (int i = 0; i < len - 1; ++i){
		if (!isPower(A[len - 1] / A[i]))
			return "NO";
	}
	return "YES";
}
//simple
string getAnswer(vector<int> A)
{
    for (int & x : A) {
        while (x % 2 == 0) {
            x /= 2;
        }
        if (x != A[0]) {
            return "NO";
        }
    }
    return "YES";
}
int main()
{
	vector<int>arr{7,7,7,7};
	cout << getAnswer(arr) << "\n";
	return 0;
}
