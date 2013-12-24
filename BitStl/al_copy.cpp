// copy algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::copy
#include <vector>       // std::vector

//template<class InputIterator, class OutputIterator>
//  OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result)
//{
//  while (first!=last) {
//    *result = *first;
//    ++result; ++first;
//  }
//  return result;
//}
int main () {
  int myints[]={10,20,30,40,50,60,70};
  std::vector<int> myvector (7);

  std::copy ( myints, myints+7, myvector.begin() );

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}