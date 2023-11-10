#include "apc.h"

int addition(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2,D_list **head_R,D_list **tail_R)
{
	int carry=0,res;
	D_list *t1=*tail1;
	D_list *t2=*tail2;
	while(t1 && t2)
	{
		res=t1->data+t2->data+carry;
		carry=res/10;
		insert_first(head_R,tail2,res%10);
		t1=t1->prev;
		t2=t2->prev;
	}
	while(t1)
	{
		res=t1->data+carry;
		carry=res/10;
		insert_first(head_R,tail_R,res%10);
		t1=t1->prev;
	}
	while(t2)
	{
		res=t2->data+carry;
		carry=res/10;
		insert_first(head_R,tail_R,res%10);
		t2=t2->prev;
	}
	return SUCCESS;

}

