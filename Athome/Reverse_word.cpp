/*单词反转you are==>are you*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
vector<string> result;
//可以提前对string执行reversed。然后输出
//也可以反向迭代
void Reverse(string& input)
{
	transform(input.begin(), input.end(), input.begin(), tolower);
	input.erase(remove_if(input.begin(),input.end(),
		[](char c){
		return  !isalnum(c)&&!isspace(c)
			; }),input.end());

	stringstream toketmp(input);
	string token;
	while (toketmp >> token)
		result.push_back(token);
	reverse(result.begin(), result.end());
}
int main()
{
	string test = "my name is bob!@#$%%";
	Reverse(test);
	for each(string v in result)
	{
		cout << v << " ";
	}
	for (auto v : result)
	{
		cout << v << " ";
	}
	return 0;
}