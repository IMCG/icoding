#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
  string s="hello";
  string out;
  transform(s.begin(), s.end(), back_inserter(out), ::toupper);
  cout << out << endl;
  // 输出：HELLO
}

#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
 
vector<int> num {2, -5, 9, 7, -2, 5, 3, 1, 0, -3, 8};
vector<int> p_num;
copy_if(num.begin(), num.end(), back_inserter(p_num), [](int i){ return (i>0);} );
int average = accumulate(p_num.begin(), p_num.end(), 0) / p_num.size();
cout << "averge: " << average << endl;