// find example
#include <iostream>     //  cout
#include <algorithm>    //  find
#include <vector>       //  vector
using namespace std;


//template<class InputIterator, class T>
//  InputIterator find (InputIterator first, InputIterator last, const T& val)
//{
//  while (first!=last) {
//    if (*first==val) return first;
//    ++first;
//  }
//  return last;
//}
int main () {
  int myints[] = { 10, 20, 30 ,40 };
  int * p;

  // pointer to array element:
  p =  find (myints,myints+4,30);
  ++p;
   cout << "The element following 30 is " << *p << '\n';

   vector<int> myvector (myints,myints+4);
   vector<int>::iterator it;

  // iterator to vector element:
  it = find (myvector.begin(), myvector.end(), 30);
  ++it;
   cout << "The element following 30 is " << *it << '\n';

  return 0;
}