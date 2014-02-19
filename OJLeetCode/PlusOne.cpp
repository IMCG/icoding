//Given a number represented as an array of digits, plus one to the number.
class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int n = digits.size() - 1;
		plus(digits, n);
		return digits;
	}
	void plus(vector<int>&digits,int n)
	{
		if (n < 0)
			return;
		if (digits[n] != 9)
			digits[n]++;
		else{
			if (n == 0){
				digits.insert(digits.begin(), 1);
				digits[n + 1] = 0;
			}
			else
				digits[n] = 0;
			plus(digits,n - 1);
		}
	}
};
