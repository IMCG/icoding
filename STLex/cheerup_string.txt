#include <string.h>
#include <iostream>
#include <vector>
   
using namespace std;
    
class Successor {
public:
    int Query(char c, int position) {
        return _table[c-1][position+1];
    }
   
    Successor(const char *T) {
        for (int c = 1; c <= 256; c++) {
            _table[c-1] = GetRow(T,c);
        }
    }
   
    ~Successor() {
        for (int i = 0; i < 256; i++) {
            delete [] _table[i];
        } 
    }
    
private:
    int *GetRow(const char *T, char c) {
        int L = strlen(T);
        int *column = new int[L+1];
        int position = -1;
        for (int j = L-1; j >= 0; j--) {
            column[j+1] = position;
            if (T[j] == c) {
                position = j;
            }
        }
        column[0] = position;
        return column;
    } 
    int *_table[256];
};
   
class SubSequenceChecker {
public:
    bool Check(const char *S) {
        int position = -1;
        while (*S != '\0') {
            position = _DS.Query(*S, position);
            if (position == -1) {
                return false;
            }
            S++;
        }
        return true;
    }
  
    SubSequenceChecker(const char *T) : _DS(T) {
    }
private:
    Successor _DS;
};

int main() {
    SubSequenceChecker s("aabcddef");
    cout << s.Check("a") << "\n";
    cout << s.Check("abcf") << "\n";
    cout << s.Check("abcdef") << "\n";
    cout << s.Check("fed") << "\n";
    cout << s.Check("aaa") << "\n";
    cout << s.Check("aafd") << "\n";
}