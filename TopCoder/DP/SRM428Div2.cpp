//ThePalindrome

#include <vector> 
#include <string> 
#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <set> 
#include <map> 
#include <queue> 
#include <math.h> 

using namespace std;

#define sz(c) (int)(c).size() 
#define all(c) (c).begin(), (c).end() 
#define fors(i,s,n) for(int i = (s); i < (n); ++i) 
#define forv(i,v) fors(i,0,sz(v)) 

bool isPalindrome(string s) {
	int i = 0, j = s.size() - 1;
	while (i < j)
		if (s[i++] != s[j--])
			return false;
	return true;
}

struct ThePalindrome {
	int find(string s) {
		int i, j;
		string add;
		for (i = 0; i < s.size(); i++)
			if (isPalindrome(s.substr(i)))
				break;
		for (j = i - 1; j >= 0; j--)
			add += s[j];
		s += add;
		return s.size();
	}
};