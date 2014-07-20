//高精度记时

auto start = chrono::high_resolution_clock::now();
register long long total = 0;
for (register int i = 0; i < 2147483647; i++)
{
    total += i;
}
cout << total << endl;
auto finish = chrono::high_resolution_clock::now();
cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << endl;

//快速幂
int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}