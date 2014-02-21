
#include <stdio.h>
 
/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n) 
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}
 
/*Main function to call above function for 0x01234567*/
int main()
{
   int i = 0x01234567;
   show_mem_rep((char *)&i, sizeof(i));
   getchar();
   return 0;
}

//Is there a quick way to determine endianness of your machine?
#include <stdio.h>
int main()
{
	unsigned int i = 1;
	/* a character pointer c is pointing to an integer */
	char *c = (char*)&i;
	if (*c)
		printf("Little endian");
	else
		printf("Big endian");
	getchar();
	return 0;
}