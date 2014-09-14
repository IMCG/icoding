//绑定不好使
#include <iostream>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;

double f(double x) 
{
    return x;
}

// std::bind works if this overloaded is commented out
float f(float x) 
{
    return x;
}

// want to bind to `f(2)`, for the double(double) version
\

//is ok
auto f_binder = std::bind(static_cast<double(&)(double)>(f), 2.);
auto f_binder = bind<double(&)(double)>(f, 2.);