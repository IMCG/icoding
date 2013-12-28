/*Author:xuesen
*@Date:12/25
*@CS106_Functor
*/
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class ShorterThan{
public:
	explicit ShorterThan(size_t maxLength) :length(maxLength){}
	bool operator() (const string&str)const{
		return str.length() < length;
	}
	/*but we alse can:
	for (size_t i = 0; i < myVector.size(); i++)
	{
		if(myVector[i].length()<length);
			++total;
	}
	*/
private:
	size_t length;
};
/*Adaptable Functions*/
