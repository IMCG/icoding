/*引出一段文字并且逆向打印*/
#include<iostream>
#include<string>
using namespace std;
int main(int argc, char*argv[])
{
	const string delims("\t,.;");
	string line;
	//for every line read successfully
	while (getline(cin, line)){
		size_t begIdx, endIdx;
		//search beginning of the first word
		begIdx = line.find_first_not_of(delims);
		//while beginning of a word found
		while (begIdx != string::npos){
			//search end of the actual word
			endIdx = line.find_first_of(delims);
			if (endIdx == string::npos){
				//end of word is end of line
				endIdx = line.length();
			}
			//print characters in reverse order
			for (int i = endIdx - 1; i >= static_cast<int>(begIdx); --i){
				cout << line[i];
			}
			cout << "　";
			//search beginning of the next word
			begIdx = line.find_first_not_of(delims, endIdx);
		}
		cout << endl;
	}
}