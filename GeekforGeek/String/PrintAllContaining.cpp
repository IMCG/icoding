//用hashMap存储原字符串  ，然后用其他再次遍历。并记录个数。len--->
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution{
public:
    vector<string>FindContain(unordered_set<string>&Myset, string&str){
        vector<string>result;
        for (auto& c : str){
            mapping[c] = 1;
        }
        this->word_size = str.length();

        for (auto& d : Myset){
            this->count = 0;// 变量位置很重要
            for (auto& c : d){
                if (mapping[c]){
                    count++;
                    mapping[c] = 0;
                }
            }
            if (count == word_size){
                result.push_back(d);
            }
            for (auto& c : str)
                mapping[c] = 1;
        }
        return result;
    }
private:
    unordered_map<char, int>mapping;
    int word_size;
    int count;
};
void print(vector<string>&result){
    for (auto& str : result){
        cout << str << endl;
    }
}
int main()
{
    system("color 5F");
    unordered_set<string>Myset{ "geeksforgeeks",
        "unsorted", "sunday", "just", "sss" };
    string str = "sun";
    Solution s;
    vector<string>result = s.FindContain(Myset, str);
    print(result);

    return 0;
}


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define NO_OF_CHARS 256

/* prints list items having all caharacters of word */
void print(char *list[], char *word, int list_size)
{
    /*Since calloc is used, map[] is initialized as 0 */
    int *map = (int *)calloc(sizeof(int), NO_OF_CHARS);
    int i, j, count, word_size;

    /*Set the values in map */
    for (i = 0; *(word + i); i++)
        map[*(word + i)] = 1;

    /* Get the length of given word */
    word_size = strlen(word);

    /* Check each item of list if has all characters
    of word*/
    for (i = 0; i < list_size; i++)
    {
        for (j = 0, count = 0; *(list[i] + j); j++)
        {
            if (map[*(list[i] + j)])
            {
                count++;

                /* unset the bit so that strings like
                sss not printed*/
                map[*(list[i] + j)] = 0;
            }
        }
        if (count == word_size)
            printf("\n %s", list[i]);

        /*Set the values in map for next item*/
        for (j = 0; *(word + j); j++)
            map[*(word + j)] = 1;
    }
}

/* Driver program to test to pront printDups*/
int main()
{
    char str[] = "sun";
    char *list[] = { "geeksforgeeks", "unsorted", "sunday", "just", "sss" };
    print(list, str, 5);
    getchar();
    return 0;
}