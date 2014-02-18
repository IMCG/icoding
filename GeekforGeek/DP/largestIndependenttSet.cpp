//http://www.geeksforgeeks.org/largest-independent-set-problem/
/*Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. A subset of 
all tree nodes is an independent set if there is no edge between any two nodes of the subset.
The largest independent set(LIS) is {10, 40, 60, 70, 80} and size of the LIS is 5.
（任意两个节点不是边）
			10
		   /  \
		  20   30
		 /  \	 \
		40 	 50   60
		    /  \
		   70   80 
*/
//A naive recursive implementation of LIS
#include <cstdio>
#include <cstdlib>
int max(int x,int y){return (x>y)?x:y;}

struct node
{
	int data;
	struct node*left,*right;
};
struct node* newNode(int data)
{
	struct node*cur = (struct node*)malloc(sizeof(struct node));
	cur->data = data;
	cur->left = cur->right = NULL;
	return cur;
}
//@@The function returns size of LIS in a given BT

/*LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X),
 *                    (sum of LISS for all children of X) }
 */
int LTSS(struct node *root)
{
	if(root==NULL)
		return 0;
	//Caculate size excluding the current node
	int size_exc1=LTSS(root->left)+LTSS(root->right);

	//Caculate size including the current node
	int size_inc1=1;
	if(root->left)
		size_inc1 += LTSS(root->left->left) + LTSS(root->left->right);
	if(root->left)
		size_inc1 += LTSS(root->right->left) + LTSS(root->right->right);
	//Return the maximum of two sizes
	return max(size_exc1,size_inc1);
}
// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    printf ("Size of the Largest Independent Set is %d ", LISS(root));
 
    return 0;
}

/*In the following solution, an additional field ‘liss’ is added to tree nodes. 
 *The initial value of ‘liss’ is set as 0 for all nodes. The recursive function
 * LISS() calculates ‘liss’ for a node only if it is not already set.
 */
/* Dynamic programming based program for Largest Independent Set problem */
#include <stdio.h>
#include <stdlib.h>
 
// A utility function to find max of two integers
int max(int x, int y) { return (x > y)? x: y; }
 
/* A binary tree node has data, pointer to left child and a pointer to 
   right child */
struct node
{
    int data;
    int liss;
    struct node *left, *right;
};
 
// A memoization function returns size of the largest independent set in
//  a given binary tree
int LISS(struct node *root)
{
    if (root == NULL)
        return 0;
 
    if (root->liss)
        return root->liss;
 
    if (root->left == NULL && root->right == NULL)
        return (root->liss = 1);
 
    // Caculate size excluding the current node
    int liss_excl = LISS(root->left) + LISS(root->right);
 
    // Calculate size including the current node
    int liss_incl = 1;
    if (root->left)
        liss_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
        liss_incl += LISS(root->right->left) + LISS(root->right->right);
 
    // Return the maximum of two sizes
    root->liss = max(liss_incl, liss_excl);
 
    return root->liss;
}
 
// A utility function to create a node
struct node* newNode(int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->liss = 0;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    printf ("Size of the Largest Independent Set is %d ", LISS(root));
 
    return 0;
}