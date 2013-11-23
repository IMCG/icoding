//write a method sort an array of strings
//so that all the anagrams are next to each other
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//function 
bool cmp1(string s1, string s2){
    sort(&s1[0], &s1[0]+s1.length());
    sort(&s2[0], &s2[0]+s2.length());
    return s1 < s2;
}
bool cmp1(string s1,string s2)
{
	sort(s2.begin(),s2.end());
	sort(s1.begin(),s1.end());
	return s1<s2;
}

int main(){
    string s[] = {
        "axyz", "abc", "yzax", "bac", "zyxa", "fg", "gf"
    };
    sort(s, s+7, cmp1);
    for(int i=0; i<7; ++i)
        cout<<s[i]<<endl;
    return 0;
}
