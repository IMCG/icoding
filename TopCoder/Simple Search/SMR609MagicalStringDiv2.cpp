//SRM 609 Div2-250
//Date :2014/4/29
#include <iostream>
#include <algorithm>
using namespace std;
class MagicalStringDiv2{
public:
	int minimalMoves(string S){
		int len = S.length();
		int a = count(S.begin(), S.begin() + len / 2,'<');
		int b = count(S.begin() + len / 2, S.end(), '>');
		return a + b;
	}
};

//先记录下来ch
int minimalMoves(string S)
{
    int n = S.size(), c = 0;
    for (int i = 0; i < n; i++) {
        char ch; //the i-th character of the wanted final string
        if (i < n/2) {
            ch = '>';
        } else {
            ch = '<';
        }
        if (S[i] != ch) {
            // cost increments
            c++;
        }
    }
    return c;
}

//python吊呀
class MagicalStringDiv2:
 def minimalMoves(self, S):
     n = len(S)
     T = '>' * (n/2) + '<' * (n/2)
     return sum( S[i] != T[i] for i in range(n) )
