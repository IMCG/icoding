#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
public:
	vector<vector<int> > threesum(vector<int>& num){
		vector<vector<int> > result;
		if(num.size()<3) return result;
	    sort(num.begin(),num.end());
		const int target=0;

		auto last=num.end();
		for(auto a=num.begin();a<prev(last,2);
			a=upper_bound(a,prev(last,2),*a)){
				for(auto b=next(a);b<prev(last);
					b=upper_bound(b,prev(last),*b)){
						const int c=target-*a-*b;
						if(binary_search(next(b),last,c))
						{
							vector<int> coll;
						    coll.push_back(*a);
							coll.push_back(*b);
							coll.push_back(c);
							result.push_back(coll);
						}

				}
		}
		return result;
	}
};
 void print(vector< vector<int> > & result)  
    {  
        
        for(int i = 0; i < result.size(); i++)  
        {  
            for(int j = 0; j < result[i].size(); j++)  
            {  
                cout<<result[i][j]<<" ";  
            }  
            cout<<endl;  
        }  
  
    }  
int main()
{
	vector<int> a;
	a.push_back(-1);
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(-1);
	a.push_back(4);
	solution s;
	s.threesum(a);
	print(s.threesum(a));  
}