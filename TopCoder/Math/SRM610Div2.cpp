#include <iostream>
#include <vector>
#include <set>
using namespace std;

int CountNumbers(vector<int> numbers)
{
    int old = 0;
    set<int> paper(numbers.begin(), numbers.end());        
    while (paper.size() > old) {
        old = paper.size();
        //不能直接对set用[]
        for (int a: paper) {
            for (int b: paper) {
                if ( (a > b) && (paper.count(a/b) == 0) ) {
                    paper.insert(a / b);
                }
            }
        }
    }
    return paper.size();
}
