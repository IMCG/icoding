//二叉搜索树，后序遍历
#include<iostream>
using namespace std;

static bool VerifyBST(int *a, int len)
{
	int root = a[len - 1];//根节点
	int i, j;
	bool result;

	if (len <= 2)return true;
	//left child
	for ( i = 0; i < len-1; i++)
	{
		if (a[i]>root)
			break;
	}
	for ( j = i; j < len-1; j++)
	{
		if (a[j] < root)
			return false;
	}

	result = VerifyBST(a, i);//递归检测左子树
	if (result)
		return VerifyBST(a + i, len - i - 1);//检测右子树

	return false;
}

int main()
{
	int a[] = { 1, 6, 4, 3, 5 };
	int a1[] = { 7, 6, 4, 3, 5 };
	if (VerifyBST(a, 5))
		cout << "a--true";
	//......
}