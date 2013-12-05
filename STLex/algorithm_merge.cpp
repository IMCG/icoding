
//// merge algorithm example
//#include <iostream>     // cout
//#include <algorithm>    // merge, sort
//#include <vector>       // vector
//using namespace std;
//
//const int N=5;
//int main () {
//  int first[] = {5,10,15,20,25};
//  int second[] = {50,40,30,20,10};
//  vector<int> v(10);
//
//  sort (first,first+N);
//  sort (second,second+N);
//  merge (first,first+5,second,second+5,v.begin());
//
//  cout << "The resulting vector contains:\n";
//  for (auto it=v.begin(); it!=v.end(); ++it)
//    cout << ' ' << *it;
//  cout << '\n';
//  return 0;
//}
// inplace_merge example
#include <iostream>     // std::cout
#include <algorithm>    // std::inplace_merge, std::sort, std::copy
#include <vector>       // std::vector

int main () {
  int first[] = {5,10,15,20,25};
  int second[] = {50,40,30,20,10};
  std::vector<int> v(10);
  std::vector<int>::iterator it;

  std::sort (first,first+5);
  std::sort (second,second+5);

  it=std::copy (first, first+5, v.begin());
     std::copy (second,second+5,it);

  std::inplace_merge (v.begin(),v.begin()+5,v.end());

  std::cout << "The resulting vector contains:";
  for (it=v.begin(); it!=v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}