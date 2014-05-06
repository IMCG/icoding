//So x+x+...+x=smiles, therefore, x must be a divisor of smiles.
#include <iostream>
#include <vector>
using namespace std;

class EmotionsDiv2{
public:
	int printSmiles(int smiles){
		int res = s;//if x = 1, then f(1) + s/1, f(1) = 0
		for (int x = 1; x < s; ++x){
		 	if(s%x==0)// x is a divisor of s
		 		res = min(res,printSmiles(x) + s/x);
		} 
	}
	return res;
};

