/* 假设a的和为sa，b的和为sb，那么他们的差值 
        diff = abs(sa-sb); 
        为了缩小差距，那么需要交换两个值，如果这两个值最接近diff/2，那么 
        交换之后diff就为0了，所以我们要尽量找到两个差值为diff/2的元素，进行交换即可 
 
        再递归即可 
    */  
  
  
#include <iostream>  
##include "cmath"
using namespace std;    
  
int a[] = { 100, 98, 99, 1, 2,3 };  
int b[] = { 1, 2,3, 4, 5 ,40};  
int g_count = 6;  
  
// 对数组进行求和  
int sum(int arr[], int n)  
{  
    int s = 0;  
    for (int i = 0; i < n; i++)  
    {  
        s += arr[i];  
    }  
    return s;  
}  
  
void swap_(int n)  
{  
    int sa = sum(a, n);  
    int sb = sum(b, n);  
    int* mi;  
    int* ma;  
    if (sa > sb) { ma = a; mi = b; }  // 根据大小来决定移动方向  
    else         { ma = b; mi = a; }  
  
    int diff = abs(sa - sb)/2;  // 数组和差值  
    if (diff == 0) return;      // 如果数组和之差是0，那么说明不需要再交换什么了  
      
    int d = 0;  
    int maxindex;  
    int minindex;  
    for (int i = 0; i < n; i++)   // 对所有的元素进行比较  
    for (int j = 0; j < n; j++)  
    {  
        int t = ma[i] - mi[j];   // 如果某对元素的差值，复合条件，并大于d，那么要更新d和当前下标  
        if (t > 0 && t <= diff && t>d)  
        {  
            d = t;  
            maxindex = i;  
            minindex = j;  
        }  
    }  
  
    if (d)  // 最后如果d大于0，那么说明有需要交换的  
    {  
        // 进行交换后递归，在寻求下一个能交换的元素  
        int t = ma[maxindex];  
        ma[maxindex] = mi[minindex];  
        mi[minindex] = t;  
        swap_(n);  
    }  
  
    // 如果d是0，那么不需要再找了，没有办法再缩小差距了  
}  
  
/* 打印数组 */  
void print(int n)  
{  
    cout <<"now a[] is:";  
    for (int i = 0; i < n; i++)  
    {  
        cout << a[i] << " ";  
    }  
    cout << endl << "now b[] is:";  
    for (int i = 0; i < n; i++)  
    {  
        cout << b[i] << " ";  
    }  
    cout << endl << "--------------------" << endl;  
}  
  
/* 测试主函数 */  
int main()  
{  
    // 先打印之前的数组  
    print(g_count);  
  
    // 进行交换  
    swap_(g_count);  
  
    // 打印交换后的数组  
    print(g_count);  
    system("pause");  
}