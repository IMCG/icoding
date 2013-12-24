#include <math.h>
#include <stdio.h>

int main( void )
{
   double y;

   y = floor( 2.8 );
   //2.000000
   printf( "The floor of 2.8 is %f\n", y );
   y = floor( -2.8 );
   //-3.00000
   printf( "The floor of -2.8 is %f\n", y );

  
}