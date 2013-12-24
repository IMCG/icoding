// unordered_map::at
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main ()
{
  typedef  unordered_map< string,int> mymap;

  mymap c1;
  c1.insert(mymap::value_type("hello",12));
  c1.insert(make_pair("good",34));
  c1.insert(mymap::value_type("home",43));

  c1.at("hello")=23;
  c1.at("good")+=16;		
  c1.at("home")=c1.at("good")+22;

  for(auto c:c1)
	  cout<<c.first<<" "<<c.second<<" "<<endl;
  cout<<endl;
  return 0;
}