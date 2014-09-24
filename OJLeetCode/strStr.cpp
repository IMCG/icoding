//Implement strStr()
//update:2014/9/24 
#include <iostream>
#include <cstring>
using namespace std;
//暴力解决AC
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(needle==NULL)return (char*)haystack;
        int i = 0,j = 0,k = 0;
        int haylen = strlen(haystack);
        int neelen = strlen(needle);
        while( i < haylen && j < neelen){
            if(*(haystack+i)==*(needle+j)){
                ++i;
                ++j;
            }else{
                j = 0;
                i = ++k;
            }
        }
        //注意:别在haystack前面加*..
        return j==neelen?(haystack+k):NULL;
    }
};

//kmp
//error
//Last executed input:	"mississippi", "a"???
class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		//
		if(!*needle)return haystack;
		int i = 0, j = 0;
		int m = strlen(needle);
		int len = strlen(haystack);
		int *next = (int*)malloc(sizeof(int)*m);
		getnext(needle, next);
		while (i < len && j < m){
			if (j == -1 || haystack[i] == needle[j]){
				++i;
				++j;
			}
			else
				j = next[j];
		}
		return j == m ? (haystack + i - j) : (char*)NULL;
	}
	void getnext(char *pattern, int next[]){
		int j = -1, i = 0;
		int len = strlen(pattern);
		//别忘了初值
		next[0] = -1;
		while (i < len){
			if (j == -1 || pattern[j] == pattern[i]){
				++i;
				++j;
				next[i] = j;
			}
			else
				j = next[j];
		}
	}
};

