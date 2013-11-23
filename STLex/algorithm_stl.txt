#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool IsOdd (int i) { return (i%2)==1; }
const int N=7;
int main()
{
	int A[]={23,45,92,47,24,78,56};
	vector<int> coll(A,A+N);

	for(auto i:coll)
		cout<<i<<" ";
	cout<<endl;

	/*partial_sort (coll.begin(), coll.begin()+3, coll.end());
	for(auto i:coll)
		cout<<i<<" ";
	cout<<endl;*/

	/*sort(coll.begin(),coll.end());

	for(auto i:coll)
		cout<<i<<" ";
	cout<<endl;*/

	/*random_shuffle(coll.begin(),coll.end());

	for(auto i:coll)
		cout<<i<<" ";
	cout<<endl;*/

	/*nth_element(coll.begin(),coll.begin()+3,coll.end());
	for(auto i:coll)
		cout<<i<<" ";
	cout<<endl;*/
	vector<int>::iterator pound;
	pound = partition (coll.begin(),coll.end(), IsOdd); //center//

	// partition algorithm example
	//#include <iostream>     // std::cout
	//#include <algorithm>    // std::partition
	//#include <vector>       // std::vector

	//bool IsOdd (int i) { return (i%2)==1; }

	//int main () {
	//  std::vector<int> myvector;

	//  // set some values:
	//  for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

	//  std::vector<int>::iterator bound;
	//  bound = std::partition (myvector.begin(), myvector.end(), IsOdd);

	//  // print out content:
	//  std::cout << "odd elements:";
	//  for (std::vector<int>::iterator it=myvector.begin(); it!=bound; ++it)
	//	std::cout << ' ' << *it;
	//  std::cout << '\n';

	//  std::cout << "even elements:";
	//  for (std::vector<int>::iterator it=bound; it!=myvector.end(); ++it)
	//	std::cout << ' ' << *it;
	//  std::cout << '\n';

	//  return 0;
	//}
}