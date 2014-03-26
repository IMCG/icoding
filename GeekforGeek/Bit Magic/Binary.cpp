//Iterative
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
}
//Recursive  递归方式
oid bin(unsigned n)
{
    /* step 1 */
    if (n > 1)
        bin(n/2);
 
    /* step 2 */
    printf("%d", n % 2);
}