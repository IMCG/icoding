//class's composition
#include<iostream>
using namespace std;

class Teacher{
};
class BirthDate{
};

class Professor:public Teacher{
private:
	BirthDate birthday;
};
