void fun1(int n)
{
	int i = 0;
	if (n > 1)
		fun1(n - 1);
	for (i = 0; i < n; i++){
		printf(" * ");
	}
	printf("\n");
}


#define LIMIT 1000
void fun2(int n)
{
	if (n <= 0)
		return;
	if (n > LIMIT)
		return;
	printf("%d ", n);
	fun2(2 * n);
	printf("%d ", n);
}
//两边扩展