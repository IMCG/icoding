#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <tchar.h>
using namespace std;
int main()
{
	ifstream input(_TEXT("E:\\a.txt"));
	string word;
	vector<string> text;
	while (input >> word)
		text.push_back(word);
	cout << "Unsorted text: \n";
	for (auto& i : text){
		cout << i << " ";
	}
	sort(begin(text), end(text));
	
	ofstream output(_TEXT("E:\\b.txt"));
	output << "sorted text : \n";
	for (auto& i : text){
		output << i << ' ';
	}
	output << endl;
	return 0;
}