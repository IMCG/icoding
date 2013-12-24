// find_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

//template<class InputIterator, class UnaryPredicate>
//  InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred)
//{
//  while (first!=last) {
//    if (pred(*first)) return first;
//    ++first;
//  }
//  return last;
//}
bool IsOdd (int i) {
  return ((i%2)==1);
}

int main () {
  std::vector<int> myvector;

  myvector.push_back(10);
  myvector.push_back(25);
  myvector.push_back(40);
  myvector.push_back(55);

  std::vector<int>::iterator it = std::find_if (myvector.begin(), myvector.end(), IsOdd);
  std::cout << "The first odd value is " << *it << '\n';

  return 0;
}