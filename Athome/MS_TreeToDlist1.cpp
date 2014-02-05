//尹成blog.0201二叉树转链表
/*1.main函数获取用户输入
@ 2.CreatTree把数字放入二叉树
@ 3.pPutInLink，遍历树。通过insert函数放入链表
@ 4.打印输出
*/
#include<iostream>
using namespace std;
//树节点
struct BSTree{
	int nValue;
	BSTree*left_child;
	BSTree*right_child;
};
//创建树，并添加节点
BSTree* CreatTree(BSTree*root, int a)
{
	if (root == nullptr)
	{
		root = new BSTree();
		root->nValue = a;
		root->left_child = nullptr;
		root->right_child = nullptr;
	}
	else if (root->nValue > a)
		root->left_child = CreatTree(root->left_child, a);
	else
		root->right_child = CreatTree(root->right_child, a);
	return root;
}
//将pRoot放入head,此时树节点变成双链表，left_child==>prev,right_child==>next
BSTree* Insert(BSTree*head, BSTree*pRoot)
{
	if (head == nullptr)
	{
		head = pRoot;
		return head;
	}
	else
	{
		pRoot->right_child = head;
		head->left_child = pRoot;
		pRoot->left_child = pRoot;

		return pRoot;
	}
}
//中序遍历二叉树
BSTree* pPutInLink(BSTree*pRoot, BSTree*&plink)
{
	if (!pRoot)
		return nullptr;
	pPutInLink(pRoot->left_child, plink);
	//处理根节点
	BSTree* temp = pRoot->right_child;
	plink = Insert(plink, pRoot);

	pPutInLink(pRoot->right_child, plink);
	return plink;
}
//input link
BSTree*print(BSTree *head)
{
	BSTree*head2 = head;
	while (head2->right_child != nullptr)
	{
		cout << head2->nValue << " ";
		head2 = head2->right_child;
	}
	cout << head2->nValue << " "<<"\npri";
	while (head2->left_child != head2)
	{
		cout << head2->nValue << " ";
		head2 = head2->left_child;
	}
	cout << head2->nValue << " ";

	return head;
}

int main()
{
	BSTree *root = nullptr;
	int a = 1;
	while (a != 0)
	{
		cout << "输入插入的数字（0停止）：";
		cin >> a;
		cout << endl;
		if (a == 0) break;
		root = CreatTree(root, a);
	}

	//转换
	BSTree *plink = nullptr;
	plink = pPutInLink(root, plink);
	print(plink);

	system("pause");
	return 0;
}
