//Bit Field
// Declares a class data member with explicit size, in bits.
//空间压缩
#include <iostream>
struct S {
 // three-bit unsigned field,
 // allowed values are 0...7
 unsigned int b : 3;
};
int main()
{
    S s = {7};
    ++s.b; // unsigned overflow
    std::cout << s.b << '\n'; // output: 0
}
//Multiple adjacent bit fields are usually packed together
#include <iostream>
struct S {
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 2 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3
    // 3 bits: unused
    unsigned char b1 : 3, : 2, b2 : 6, b3 : 2;
};
int main()
{
    std::cout << sizeof(S) << '\n'; // usually prints 2
}