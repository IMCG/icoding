
//IsWordPalidrome
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<iterator>
using namespace std;
bool IsNotAlphaOrSpace(char ch)
{
	return !isalpha(ch) && !isspace(ch);
}
bool IsWordPalidrome(string input)
{
	input.erase(remove_if(input.begin(), input.end(), IsNotAlphaOrSpace),
		input.end());
	transform(input.begin(), input.end(), input.begin(), tolower);
	stringstream tokenizer(input);
	vector<string> tokens;

	string token;
	while (tokenizer >> token)
		tokens.push_back(token);

	//tokens.insert(tokens.begin(), istream_iterator<string>(tokenizer),
		//istream_iterator<string>());
	return equal(tokens.begin(), tokens.begin() + tokens.size() / 2, tokens.rbegin());
}
int main()
{
	
}