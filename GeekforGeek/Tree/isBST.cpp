// METHOD 2 (Correct but not efficient)
/* Returns true if a binary tree is a binary search tree */
int isBST(struct node* node) 
{ 
  if (node == NULL) 
    return(true); 
     
  /* false if the max of the left is > than us */
  if (node->left!=NULL && maxValue(node->left) > node->data) 
    return(false); 
     
  /* false if the min of the right is <= than us */
  if (node->right!=NULL && minValue(node->right) < node->data) 
    return(false); 
   
  /* false if, recursively, the left or right is not a BST */
  if (!isBST(node->left) || !isBST(node->right)) 
    return(false); 
     
  /* passing all that, it's a BST */
  return(true); 
} 


int isBSTUtil(struct node* node, int min, int max);
 
/* Returns true if the given tree is a binary search tree 
 (efficient version). */
int isBST(struct node* node) 
{ 
  return(isBSTUtil(node, INT_MIN, INT_MAX)); 
} 

 // METHOD 3 (Correct and Efficient)
/* Returns true if the given tree is a BST and its 
   values are >= min and <= max. */
int isBSTUtil(struct node* node, int min, int max) 
{ 
 
  /* an empty tree is BST */
  if (node==NULL) 
     return 1;
       
  /* false if this node violates the min/max constraint */ 
  if (node->data < min || node->data > max) 
     return 0; 
 
  /* otherwise check the subtrees recursively, 
   tightening the min or max constraint */
  return
    isBSTUtil(node->left, min, node->data-1) &&  // Allow only distinct values
    isBSTUtil(node->right, node->data+1, max);  // Allow only distinct values
} 
