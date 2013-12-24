// find_end example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_end
#include <vector>       // std::vector

//template<class ForwardIterator1, class ForwardIterator2>
//  ForwardIterator1 find_end (ForwardIterator1 first1, ForwardIterator1 last1,
//                             ForwardIterator2 first2, ForwardIterator2 last2)
//{
//  if (first2==last2) return last1;  // specified in C++11
//
//  ForwardIterator1 ret = last1;
//
//  while (first1!=last1)
//  {
//    ForwardIterator1 it1 = first1;
//    ForwardIterator2 it2 = first2;
//    while (*it1==*it2) {    // or: while (pred(*it1,*it2)) for version (2)
//        ++it1; ++it2;
//        if (it2==last2) { ret=first1; break; }
//        if (it1==last1) return ret;
//    }
//    ++first1;
//  }
//  return ret;
//}
bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {1,2,3,4,5,1,2,3,4,5};
  std::vector<int> haystack (myints,myints+10);

  int needle1[] = {1,2,3};

  // using default comparison:
  std::vector<int>::iterator it;
  it = std::find_end (haystack.begin(), haystack.end(), needle1, needle1+3);

  if (it!=haystack.end())
    std::cout << "needle1 last found at position " << (it-haystack.begin()) << '\n';

  int needle2[] = {4,5,1};

  // using predicate comparison:
  it = std::find_end (haystack.begin(), haystack.end(), needle2, needle2+3, myfunction);

  if (it!=haystack.end())
    std::cout << "needle2 last found at position " << (it-haystack.begin()) << '\n';

  return 0;
}