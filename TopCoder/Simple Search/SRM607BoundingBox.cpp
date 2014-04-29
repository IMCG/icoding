//SRM 607 Div2-250
//Date :2014/4/29
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class BoundingBox{
public:
	int smallestArea(vector<int> X, vector<int> Y){
		auto a = minmax_element(X.begin(), X.end());
		auto b = minmax_element(Y.begin(), Y.end());
		int weight = *a.first - *a.second;
		int height = *b.first - *b.second;
		return weight*height;
	}
};
//python
class BoundingBox:
 def smallestArea(self, X, Y):
    return ( max(X)-min(X) ) * ( max(Y)-min(Y) )