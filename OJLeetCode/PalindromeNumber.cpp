/*Author:xuesen
  Data:12/21
  Palindrome Number
  Determine whether an integer is a palindrome. Do this without extra space.
  1.You could also try reversing an integer
*/
class Solution{
public:
	bool isPalindrome(int x){
		if (x < 0)return false;
		int div = 1;
		while (x / div >= 10)
			div *= 10;
		while (x){
			int l = x / div;
			int r = x % 10;
			if (l != r)return false;
			x = (x%div) / 10;
			div /= 100;
		}
		return true;
	}
};
//a recursive solution
bool isPalindrome(int x, int &y) {
	if (x < 0) return false;
	if (x == 0) return true;
	if (isPalindrome(x / 10, y) && (x % 10 == y % 10)) {
		y /= 10;
		return true;
	}
	else {
		return false;
	}
}
bool isPalindrome(int x) {
	return isPalindrome(x, x);
}