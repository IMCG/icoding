//SMR 612 Div2-250
#include <iostream>
#include <string>
using namespace std;
class LeftAndRightHandedDiv2{
public:
	int count(string S){
		int count = 0;
		for (size_t i = 0; i < S.length(); i++)
		{
			if (S[i] == 'R'){
				if (S[++i] == 'L')
					count++;
				else
					i--;
			}
		}
		return count;
	}
};

// 
int count(string S)
{
    int c = 0;
    // Count RL in string:
    for (int i = 0; i + 1 != S.size(); i++) {
        if ( (S[i] == 'R') && (S[i+1] == 'L') ) {
            c++;
        }
    }
    return c;
}
//Python
class LeftAndRightHandedDiv2:
 def count(self, S):
    return S.count('RL')
