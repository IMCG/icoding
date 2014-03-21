//Use Sorting

// 其实就是用一个		HashMap
// 1) Use a sorting algorithm to sort the elements O(nlogn)    
// 2) Scan the sorted array and construct a 2D array of element and count O(n).
// 3) Sort the 2D array according to count O(nlogn).

//Use BST and Sorting
/* Insert elements in BST one by one and if an element is already present 
 then increment the count of the node. Node of the Binary Search Tree 
 (used in this approach) will be as follows.
 struct tree
{
  int element;
  int first_index //To handle ties in counts
  int count;
}BST;
2.Store the first indexes and corresponding counts of BST in a 2D array.
3 Sort the 2D array according to counts (and use indexes in case of tie).
*/



