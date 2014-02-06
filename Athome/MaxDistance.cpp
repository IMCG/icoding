#include <iostream>  
#include <stack>  
using namespace std;  
  
// 树节点定义  
template<class T>  
class BiTNode  
{  
public:  
    T nValue; // 值  
    BiTNode<T> *pLChild; // 左儿子节点  
    BiTNode<T> *pRChild; // 右儿子节点  
};  
  
  
// 二叉树类  
template<class T>  
class BiTree  
{  
public:  
    BiTree();  // 构造函数  
    ~BiTree(); // 析构函数  
    BiTNode<T> *Create();  
    BiTNode<T> *getRoot();  
    void InOrder(BiTNode<T>  *p);  
    void PostOrder(BiTNode<T>  *p);  
    void PreOrder(BiTNode<T>  *p);  
    void Visit(BiTNode<T>  *p);  
    int GetDeep(BiTNode<T>  *p);  
    int GetMaxLengh();  
  
private:  
    BiTNode<T> *pRoot;  
    int maxlengh;  
};  
  
template<class T>  
BiTree<T>::BiTree()  
{  
    pRoot = new BiTNode<T>;  
}  
  
template<class T>  
BiTree<T>::~BiTree()  
{  
  
}  
  
/* 通过键盘输入创建树 */  
template<class T>  
BiTNode<T> *BiTree<T>::Create()  
{  
    T nValue;  
    BiTNode<T> *nRoot;  
    scanf_s("%d", &nValue);  
    if (nValue == 0)  
    {  
        nRoot = NULL;  
    }  
    else  
    {  
        nRoot = new BiTNode<T>;  
        if (NULL == nRoot)  
        {  
            printf("分配内存失败!\n");  
        }  
        else  
        {  
            nRoot->nValue = nValue;  
            printf("请输入%d结点的左子结点:", nRoot->nValue);  
            nRoot->pLChild = Create();  
  
            printf("请输入%d结点的右子结点:", nRoot->nValue);  
            nRoot->pRChild = Create();  
        }  
    }  
    pRoot = nRoot;  
    return nRoot;  
}  
  
template<class T>  
void BiTree<T>::Visit(BiTNode<T> *p)  
  
{  
    cout << p->nValue;  
}  
template<class T>  
BiTNode<T> *BiTree<T>::getRoot()  
{  
    return pRoot;  
}  
  
/* 先序遍历 */  
template<class T>  
void BiTree<T>::PreOrder(BiTNode<T> *pRoot)  
{  
    if (pRoot == NULL)  
    {  
        return;  
    }  
    else  
    {  
        /* 先序遍历先访问根节点，再遍历左子树也右子树 */  
        Visit(pRoot);  
        PreOrder(pRoot->pLChild);  
        PreOrder(pRoot->pRChild);  
  
    }  
}  
  
/* 中序遍历，参考先序遍历 */  
template<class T>  
void BiTree<T>::InOrder(BiTNode<T> *pRoot)  
{  
    if (pRoot == NULL)  
    {  
        return;  
    }  
    else  
    {  
  
        PreOrder(pRoot->pLChild);  
        Visit(pRoot);  
        PreOrder(pRoot->pRChild);  
  
    }  
}  
  
/* 后序遍历，参照先序遍历 */  
template<class T>  
void BiTree<T>::PostOrder(BiTNode<T> *pRoot)  
{  
    if (pRoot == NULL)  
    {  
        return;  
    }  
    else  
    {  
  
        PreOrder(pRoot->pLChild);  
        PreOrder(pRoot->pRChild);  
        Visit(pRoot);  
  
    }  
}  
  
/* 取最远距离 */  
template<class T>  
int BiTree<T>::GetMaxLengh()   //每一个节点左右深度相加比较最大值  
{  
    int maxlengh = 0;  
    int deep = 0;  
    int lengh = 0;  
    if (pRoot == NULL)  
    {  
        return 0;  
    }  
  
    // 获取左子树和右子树高度再相加就行  
    lengh = GetDeep(pRoot->pLChild) + GetDeep(pRoot->pRChild) + 2;  
    if (maxlengh < lengh)  
    {  
        maxlengh = lengh;  
    }  
  
    return maxlengh;  
}  
  
/* 
    获取树的深度，方法为比较左子树和右子树深度，取比较大的那个值+1就行 
    */  
template<class T>  
int BiTree<T>::GetDeep(BiTNode<T>  *pRoot)  
{  
    // 如果为root为NULL，则深度为0  
    if (pRoot == NULL)  
    {  
        return 0;  
    }  
  
    // 分别取左子树深度和右子树深度  
    int ld = GetDeep(pRoot->pLChild);  
    int rd = GetDeep(pRoot->pRChild);  
  
    // 返回大的那个+1  
    if (ld > rd)  
        return ld + 1;  
  
    return rd + 1;  
}  
  
int main()  
{  
    printf("请输入根结点的值:");  
    BiTree<int> pRoot;  
    pRoot.Create();  
  
    printf("前序遍历:");  
    pRoot.PreOrder(pRoot.getRoot());  
    cout << endl;  
    printf("中序遍历:");  
    pRoot.InOrder(pRoot.getRoot());  
    cout << endl;  
    printf("后序遍历:");  
    pRoot.PostOrder(pRoot.getRoot());  
    cout << endl << "深度" << endl;  
  
    cout << pRoot.GetDeep(pRoot.getRoot());  
  
    // 在此处计算最大距离  
    cout << endl << "最长距离";  
    cout << pRoot.GetMaxLengh();  
    system("pause");  
    return 0;  
}  