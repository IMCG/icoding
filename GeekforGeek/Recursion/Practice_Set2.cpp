/* Assume that n is greater than or equal to 1 */
int fun1(int n)
{
  if(n == 1)
     return 0;
  else
     return 1 + fun1(n/2);
} 
// Answer: The function calculates and returns 
//	log(n)/log2

/* Assume that n is greater than or equal to 0 */
void fun2(int n)
{
  if(n == 0)
    return;
 
  fun2(n/2);
  printf("%d", n%2);
}  
// Answer: The function fun2() prints binary equivalent of n.