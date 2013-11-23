#include<iostream>
#include<string>
using namespace std;

//def subsequence
bool myCmp(string S, string T) {
	int lenS = S.length();
	int lenT = T.length();
	int i = 0, j = 0;
	for (; i < lenS, j < lenT; j++) {
		if (S[i] == T[j]) i++;
	}
	return i == lenS ? true : false; 
}

bool match(string input,string pattern)
{
	int i=0,j=0;
	int count=0;
	if(input.size()<pattern.size()) return false;
	while(i<input.size() && j<pattern.size())
	{
		if(input[i]==pattern[j]){
			i++,j++;
		count++;
		if(count==pattern.length())
			return true;
		}else
			i++;
	}
	return false;
}
int main()
{
	string input="abdfg";
	string pattern="fga";
	cout<<match(input,pattern)<<endl;
}
