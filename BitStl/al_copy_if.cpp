// copy_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::copy_if, std::distance
#include <vector>       // std::vector

//template <class InputIterator, class OutputIterator, class UnaryPredicate>
//  OutputIterator copy_if (InputIterator first, InputIterator last,
//                          OutputIterator result, UnaryPredicate pred)
//{
//  while (first!=last) {
//    if (pred(*first)) {
//      *result = *first;
//      ++result;
//    }
//    ++first;
//  }
//  return result;
//}
int main () {
  std::vector<int> foo = {25,15,5,-5,-15};
  std::vector<int> bar (foo.size());

  // copy only positive numbers:
  auto it = std::copy_if (foo.begin(), foo.end(), bar.begin(), [](int i){return !(i<0);} );
  bar.resize(std::distance(bar.begin(),it));  // shrink container to new size

  std::cout << "bar contains:";
  for (int& x: bar) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}