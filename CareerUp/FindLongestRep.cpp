//http://www.careercup.com/question?id=5680360385937408
/*Find the longest repeating character in a sorted string
 *1.可以利用sorted的特性。遍历一次数组。
 *2.也可以用一个额外的数组，记录各个字符的多少
*/
#include <iostream>
#include <string>
using namespace std;
char FindLongestRep(string&str)
{
	char cur_char = str[0], max_char = str[0];
	int cur_cnt = 1, max_cnt = 1;
	for (size_t i = 1; i < str.length(); i++)
	{
		if (str[i] == cur_char)
		{
			cur_cnt++;
			if (cur_cnt>max_cnt)
			{
				max_cnt = cur_cnt;
				max_char = cur_char;
			}
		}
		else{
			cur_cnt = 1;
			cur_char = str[i];
		}
	}
	return max_char;
}
int main()
{
	string str = "aabbbccccdefffg";
	char result = FindLongestRep(str);
	cout << result;
}