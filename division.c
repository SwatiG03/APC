#include "apc.h"
int division(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2,D_list **head_R,D_list **tail_R)
{
	int count=0;
	while(compare(head1,tail1,head2,tail2)==SUCCESS) //Calling subtraction till head1 becomes less than head2
	{
		subtraction(head1,tail1,head2,tail2,head_R,tail_R);
		count++;							//Incrementing count
		copy(head1,tail1,head_R,tail_R);
		Delete_list(head_R,tail_R);
	}
	return count+1;
}


int compare(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2)
{
	int count1=0,count2=0;
	D_list *temp=*head1;
	while(temp)
	{
		count1++;
		temp=temp->next;
	}
	temp=*head2;
	while(temp)
	{
		count2++;
		temp=temp->next;
	}
	if(count1>count2)
		return SUCCESS;
	else if(count1==count2)
	{
		if((*head1)->data > (*head2)->data)
			return SUCCESS;
		else
			return FAILURE;
	}
	else
		return FAILURE;
}

