//typename item5
#include<iostream>

class Rose{};

class A{public:typedef Rose rose;};

template<typename T>
class B:public T{public:typedef typename T::rose foo;};

template<typename T>
void smell(T) {std::cout<<"awful\n";}

void smell(Rose) {std::cout<<"sweet\n";}

int main()
{
	smell(A::rose());
	smell(B<A>::foo());    //:-)
}
