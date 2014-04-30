//SRM 614 DIV2 
//Date 2014/4/29
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class MicroStrings{
public:
	string makeMicroString(int A, int D){
		stringstream ss;
		ss << A;
		int t = A - D;
		while (t >= 0){
			ss << t;
			t -= D;
		}
		return ss.str();
	}
};
//good 
string makeMicroString(int A, int D) {
  string micro = "";
  while (A >= 0) {
    micro += to_string(A);//to_string.
    A -= D;
  }
  return micro;
}