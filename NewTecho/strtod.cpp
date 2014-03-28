/*Convert string to double  
float       strtof( const char* str, char** str_end );
double      strtod( const char* str, char** str_end );
long double strtold( const char* str, char** str_end );

*/

/* strtod example */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtod */

int main ()
{
  char szOrbits[] = "365.24 29.53";
  char* pEnd;
  double d1, d2;
  d1 = strtod (szOrbits, &pEnd);
  d2 = strtod (pEnd, NULL);
  printf ("The moon completes %.2f orbits per Earth year.\n", d1/d2);
  return 0;
}

#include <cstdlib>
#include <iostream>
 
int main()
{
    std::cout << std::strtod("0.0000000123", nullptr) << "\n";
 
    // the second arg of strto* is non-const. We must copy the string
    char src[] = "0.012  15e16 -0x1afp-2 inF Nan";
    char* c = src;
 	//第二个参数是剩余的部分。
    std::cout << std::strtod(c, &c) << "\n";
    std::cout << std::strtod(c, &c) << "\n";
    std::cout << std::strtod(c, &c) << "\n";
    std::cout << std::strtod(c, &c) << "\n";
    std::cout << std::strtod(c, &c) << "\n";
}
/*
1.23e-08
0.012
1.5e+17
-107.75
inf
nan
*/