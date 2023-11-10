#include "apc.h"
int multiplication(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2,D_list **head_R,D_list **tail_R)
{
	insert_first(head_R,tail_R,0);
	D_list *hr1=NULL;
	D_list *tr1=NULL;
	D_list *hr=NULL;
	D_list *tr=NULL;
	int res;
	D_list *t2=*tail2;
	int count=0;
	while(t2)
	{
		int carry=0;
		for(int i=0;i<count;i++)
		{
			insert_last(&hr1,&tr1,0);
		}
		count++;
		D_list *t1=*tail1;
		while(t1)
		{
			res=t1->data*t2->data+carry;
			carry=res/10;
			insert_first(&hr1,&tr1,res%10);
			t1=t1->prev;
		}
		if(carry!=0)
			insert_first(&hr1,&tr1,carry);
		addition(&hr1,&tr1,head_R,tail_R,&hr,&tr);
		copy(head_R,tail_R,&hr,&tr);
		Delete_list(&hr,&tr);
		Delete_list(&hr1,&tr1);
		t2=t2->prev;
	}
	return SUCCESS;
}
