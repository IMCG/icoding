//Date 2014/4/29
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class InterestingNumber{
public:
	string isInteresting(string x){
		for (auto i = x.begin(); i != x.end(); ++i)
		{
			auto e = find_if(next(i), x.end(), [i](char c){return c == *i; });
			if (e != x.end())
			{
				//int a = distance(i, e) - 1;
				//int b = *i-'0';
				//cout << a << " "<< b<<"\n";
				//cout << distance(i, e) - 1 << " " << *i << "\n";
				//这里要把字符转换为整数。bug了好久
				if ((distance(i, e) - 1) != *i-'0')
					return "Not interesting";
			}
		}
		return "Interesting";
	}
	//用vector记录下来
	string isInteresting(string x)
	{
	    for (int d = 0; d < 10; d++) {
	        vector<int> p; //list of positions equal to d
	        for (int i = 0; i < x.size(); i++) {
	            if (x[i] == '0' + d) {
	                p.push_back( i );
	            }
	        }
	        // if digit doesn't exist in x, it is already valid.
	        if (p.size() == 0) {
	            continue;
	        }
	        if (p.size() == 2) {
	            if ( p[1] != p[0] + d + 1 ) {
	                return "Not interesting";
	            }
	        } else {
	            return "Not interesting";
	        }
	    }
	    return "Interesting";
	}
};

//Python
class InterestingNumber:
 def isInteresting(self, x):
    for d in range(10):
        ch = chr(d + ord('0') )
        # if ch is not in x, then there are zero positions and it is valid
        if ch in x:
            # find the indexes that contain ch:
            indexes = [ i for i in range( len(x) ) if x[i] == ch ]
            # number of positions must be 2, and the distance should be:
            if len(indexes) != 2 or indexes[1] - indexes[0] - 1 != d:
                return "Not interesting"
    return "Interesting"