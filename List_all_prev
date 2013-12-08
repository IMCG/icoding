int Count(node*head,int searchFor)
{
	int count=0;
	node*current=head;
	while(current!=nullptr)
	{
		if(current->data==searchFor)
			count++;
		current=current->next;
	}
	return count;
}
int GetNth(node*head,int index)
{
	int i=0;
	node*current=head;
	while(i<index && current!=nullptr)
	{
		current=current->next;
		i++;
	}
	return current->data;
}
void DeleteList(node* &head)
{
	node*current=head;
	node*cur_next=current->next;
	while(cur_next!=nullptr)
	{
		//cur_next=current->next;
		//free(current);
		//current=cur_next;
		current->next=cur_next->next;
		free(cur_next);
		cur_next=current->next;
	}
	head=nullptr;
}
int Pop(node* &head)
{
	int res;
	node*current=head;
	head=current->next;
	res=current->data;
	//current->next=nullptr;
	delete current;
	return res;
}
void InsertNth(node* &head,int index,int data)
{
	if(index==0) Push(head,data);
	else{
		node*current=head;
		int i=0;
		while(i<index-1 && current!=nullptr)
		{
			current=current->next;
			i++;
		}
		Push(current->next,data);
	}
}
