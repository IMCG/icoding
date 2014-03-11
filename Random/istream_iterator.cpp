#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
	//create istream iterator 
	istream_iterator<int>Read(cin);
	//create end-of-stream iterator
	istream_iterator<int>ReadEOF;
	while (Read != ReadEOF){
		cout << "once: " << *Read << endl;
		cout << "once again: " << *Read << endl;
		++Read;
	}
	return 0;
}