//Div 2-250
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class LittleElephantAndBooks{
public:
	int getNumber(vector<int>pages, int number){
		sort(pages.begin(), pages.end());
		int num = accumulate(pages.begin(), pages.begin() + number,0);
		return num - pages[number - 1] + pages[number];
	}
};

//即不处理第number-1个
int getNumber(vector<int> pages, int number)
{
    // Result is equal to the sum of the number-1 smallest book and
    // the number-th smallest book:
    sort(pages.begin(), pages.end());
    int s = pages[number];
    for (int i=0; i < number - 1; i++) {
        s += pages[i];
    }
    return s;
}
