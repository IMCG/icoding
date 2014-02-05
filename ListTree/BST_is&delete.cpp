//binary search tree
#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode*MakeEmpty(TreeNode*T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->left);
		MakeEmpth(T->right);
		delete T;
	}
	return NULL;
}
TreeNode*Find(TreeNode*T,int x)
{
	if(T==NULL)return NULL;
	if(x<T->val)
		return Find(T->left);
	else 
	if(x>T->val)
		return Find(T->right);
	else
		return T;
}
TreeNode* FindMin(TreeNode*T)
{
	if(T==NULL)return NULL;
	else
	if(T->left==NULL)
		return T;
	else
		return FindMin(T->left);
	//if(T)return T->val;
}
int FindMin2(TreeNode*T)
{
	if(T==NULL)return -1;
	//is T->left
	while(T->left!=NULL)
	{
		T=T->left;
	}
	return T->val;
}
TreeNode*newNode(int elem)
{
	TreeNode*current=new TreeNode(elem);
	current->left=NULL;
	current->right=NULL;
	return current;
}
TreeNode*Insert(TreeNode*T,int elem)
{
	if(T==NULL)
		return newNode(elem);
	/*if(T==NULL)
	{
		T=malloc(sizeof(TreeNode));
		if(T==NULL)
			FatalError("Out of space");
		else
			{
				T->val=elem;
				T->left=T->right=NULL;
			}
	}*/
	if(elem<=T->val)
		T->left=Insert(T->left,elem);
	else
		T->right=Insert(T->right,elem);
	return T;
}
TreeNode*Delete(TreeNode*T,int x)
{
	TreeNode*Temp;
	if(T==NULL)return NULL;
	else if(x<T->val)
		T->left=Delete(T->left,x);
	else if(x>T->val)
		T->right=Delete(T->right,x);
	else//find element to be deleted
	if(T->right && T->left)
	{
		Temp=FindMin(T->right);
		T->val=Temp->val;
		T->right=Delete(T->right,T->val);
	}
	else//one of zero children
	{
		Temp=T;
		if(T->left==NULL)
			T->T->right;
		else if(T->right==NULL)
			T=T->left;
		delete Temp;
	}
	return T;
}
bool isBST(node*head)
{
	if (head == nullptr)
		return false;
	else if (head->left&& minValue(head->left) > head->data)
		return false;
	else if (head->right&&maxValue(head->right) < head->data)
		return false;
	return isBST(head->left) && isBST(head->right);
}
int main()
{

}