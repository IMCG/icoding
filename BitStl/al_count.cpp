// count algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::count
#include <vector>       // std::vector

//template <class InputIterator, class T>
//  typename iterator_traits<InputIterator>::difference_type
//    count (InputIterator first, InputIterator last, const T& val)
//{
//  typename iterator_traits<InputIterator>::difference_type ret = 0;
//  while (first!=last) {
//    if (*first == val) ++ret;
//    ++first;
//  }
//  return ret;
//}
int main () {
  // counting elements in array:
  int myints[] = {10,20,30,30,20,10,10,20};   // 8 elements
  int mycount = std::count (myints, myints+8, 10);
  std::cout << "10 appears " << mycount << " times.\n";

  // counting elements in container:
  std::vector<int> myvector (myints, myints+8);
  mycount = std::count (myvector.begin(), myvector.end(), 20);
  std::cout << "20 appears " << mycount  << " times.\n";

  return 0;
}