//Easiest way to convert int to string


//1
int a = 10;
char *intStr = itoa(a);   //char *
string str = string(intStr);

//2
int a = 10;
stringstream ss;
ss << a;
string str = ss.str();

//3
std::string s = std::to_string(42);

//4 boost
#include <boost/lexical_cast.hpp>
int num = 4;
std::string str = boost::lexical_cast<std::string>(num);

