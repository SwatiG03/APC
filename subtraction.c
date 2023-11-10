#include "apc.h"
int subtraction(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2,D_list **head_R,D_list **tail_R)
{
	int borrow=0,res;
	D_list *t1=*tail1;
	D_list *t2=*tail2;
	while(t1 && t2)
	{
		t1->data=t1->data-borrow;
		if(t1->data >= t2->data)
		{
			res=t1->data-t2->data;
			insert_first(head_R,tail_R,res);                                                       
			borrow=0;
		}
		else
		{
			t1->data=10+t1->data;
			res=t1->data-t2->data;
			insert_first(head_R,tail_R,res);                                                       
			borrow=1;
		}
		t1=t1->prev;
		t2=t2->prev;
	}
	while(t1)
	{
		if(t1->data<borrow)
		{
			res=t1->data+10-borrow;
			borrow=1;
		}
		else
		{
			res=t1->data-borrow;
			borrow=0;
		}
		insert_first(head_R,tail_R,res);
		t1=t1->prev;
	}
	D_list *temp=*head_R;
	while(temp->data==0 && temp->next!=NULL)
	{
		Delete_first(head_R,tail_R);
		temp=temp->next;
	}
	return SUCCESS;
}
