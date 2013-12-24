// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

//template <class ForwardIterator, class T>
//  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
//{
//  ForwardIterator it;
//  iterator_traits<ForwardIterator>::difference_type count, step;
//  count = distance(first,last);
//  while (count>0)
//  {
//    it = first; step=count/2; advance (it,step);
//    if (*it<val) {                 // or: if (comp(*it,val)), for version (2)
//      first=++it;
//      count-=step+1;
//    }
//    else count=step;
//  }
//  return first;
//}
int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}