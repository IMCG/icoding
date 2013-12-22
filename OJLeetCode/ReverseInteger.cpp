/*Author:xuesen
 Data:12/21
 Reverse digits of an integer.

 Example1: x = 123, return 321
 Example2: x = -123, return -321
*/
#include<iostream>
using namespace std;
class Solution{
public:
	int reverse(int x){
		int result = 0;
		for (; x != 0; x /= 10){
			result = result * 10 + x % 10;
		}
		return result;
	}
};
class Solution1{
public:
	void reverse(int x){
		if (x <= 0){
			cout << "-";
			x = -x;
		}
		while (x){
			cout << x % 10;
			x = x / 10;
		}
	}
};
int main()
{
	int test = -123;
	Solution1 s;
	s.reverse(test);
}