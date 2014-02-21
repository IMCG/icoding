//Practice questions for Linked List and Recrusion

void fun1(struct node* head)
{
  if(head == NULL)
    return;
  
  fun1(head->next);
  printf("%d  ", head->data);
}
//fun1() prints the given Linked List in reverse manner. For Linked List
// 1->2->3->4->5, fun1() prints 5->4->3->2->1.

void fun2(struct node* head)
{
  if(head== NULL)
    return;
  printf("%d  ", head->data); 
 
  if(head->next != NULL )
    fun2(head->next->next);
  printf("%d  ", head->data);   
}
//fun2() prints alternate nodes of the given Linked List,For Linked List
// 1->2->3->4->5, fun2() prints 1 3 5 5 3 1.

