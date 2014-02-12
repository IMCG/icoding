//C++正则表达式
#include <iostream>
#include <string>
#include <regex>
#include <cstring>
#include <cassert>
using namespace std;
int main()
{
	char const s[] = "Kerr,Kenny";
	auto m = cmatch{};
	assert(m.empty());
	string name, family;
	if (regex_match(s, m, regex{ R"((\w+)(\w+))" }))
	{
		name = m[1].str();
		family = m[2].str();
	}
	else if (regex_match(s, m, regex{ R"((\w+),(\w+))" }))
	{
		name = m[2].str();
		family = m[1].str();
	}
	else
	{
		printf("No match\n");
	}
}#include<iostream>
#include<regex>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
struct strip{
	char const*first;
	char const*last;
	strip(char const* const begin, char const* const end) :first(begin), last(end){}
	strip() :strip(nullptr, nullptr){}
};

auto begin(strip const&s)->char const*{
	return s.first;
}
auto end(strip const&s)->char const*{
	return s.last;
}
template<unsigned Count>
//make_strip 帮助函数
auto make_strip(char const(&test)[Count])->strip
{
	return strip{ text, text + Count - 1 };
}

//strip's size
auto size(strip const&s)->unsigned
{
	return end(s) - begin(s);
}
//通过strip创建标准字符串
auto to_string(strip const&s)->string
{
	return string{ begin(s), end(s) };
}
int main()
{
	auto s = make_strip("Kerr,Kenny");
	for (auto& c : s)
	{
		printf("%c\n", c);
	}
}




