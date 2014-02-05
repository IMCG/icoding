#include<iostream>
#include<algorithm>
using namespace std;
//I just want to see what can accur.
bool isPalindrome1(string text)
{
	text.erase(remove_if(text.begin(), text.end(),
		[](char c){					//lambda
		return !isalpha(c)
			; }), text.end());
		transform(text.begin(), text.end(), text.begin(), tolower);
		return equal(text.begin(), text.begin() + text.size() / 2, text.rbegin());
}
bool isPalindrome2(string text)
{

	transform(text.begin(), text.end(), text.begin(), tolower);
	auto left = text.begin();
	auto right = prev(text.end());
	while (left < right)
	{
		if (!::isalpha(*left))  ++left;
		else if (!::isalpha(*right))  --right;
		else if (*left != *right) return false;
		++left;
		--right;
	}
	return true;
}
bool isPalindrome(string s) {
	for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
	{
		while (i < j && !isalpha(s[i])) i++;
		while (i < j && !isalpha(s[j])) j--;

		if (tolower(s[i]) != tolower(s[j]))
			return false;
	}
	return true;
}
int main()
{
	string text = "abcD48dC*bA)";
	if (isPalindrome2(text))
		cout << "hello";
	else
		cout << "wong";
}
//islanum=isalpha+isdigit