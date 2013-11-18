//next smallest and next largest 
#include<iostream>
using namespace std;

int Count_1_of_bits(int x)
{
	int count=0;
	while(x)
	{
		x&=(x-1);
		count++;
	}
	return count;
}
int find_biger(int x)
{
	int smaller=x&(-x);
	int ripple=x+smaller;
	int ones=x^ripple;
	ones=(ones>>2)/smaller;
	
	return ripple | ones;
}
+int next1(int x){
+    int xx = x, bit = 0;
+    for(; (x&1) != 1 && bit < 32; x >>= 1, ++bit);
+    for(; (x&1) != 0 && bit < 32; x >>= 1, ++bit);
+    if(bit == 32) return -1; //11100...00, none satisify
+    x |= 1;
+    x <<= bit;
+    int num1 = count_one(xx) - count_one(x);
+    int c = 1;
+    for(; num1 > 0; x |= c, --num1, c <<= 1);
+    return x;
+}
+int previous1(int x){
+    int xx = x, bit = 0, found = 0;
+    for(int i=0; i<32 && x!=0; ++i){
+        if(!(x&1) && ((x>>1)&1)){
+            found = 1;
+            break;
+        }
+        x >>= 1;
+        ++bit;
+    }
+    if(!found) return -1; //000...111, none satisify
+    x ^= 3;
+    int num1 = count_one(xx) - count_one(x);
+    for(; num1 > 0; x = (x<<1) | 1, --num1, --bit);
+    for(; bit > 0; x <<= 1, --bit);
+    return x;
+}

int main()
{
	int x=18;
	int y=18;
	int c1=Count_1_of_bits(x);
	while(true)
	{
		x++;
		if(Count_1_of_bits(x)==c1)
		{
			cout<<x<<endl;
			break;
		}
	}
	cout<<find_biger(y)<<endl;
	return 0;
}