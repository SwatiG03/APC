#include "apc.h"
int insert_first(D_list **head,D_list **tail,int data)
{
	D_list *new=malloc(sizeof(D_list));
	if(new==NULL)
		return FAILURE;
	new->data=data;
	new->next=NULL;
	new->prev=NULL;
	if(*head==NULL)
	{
		*head=new;
		*tail=new;
		return SUCCESS;		
	}
	new->next=*head;
	(*head)->prev=new;
	*head=new;
	return SUCCESS;
}

int insert_last(D_list **head,D_list **tail,int data)
{
	D_list *new=malloc(sizeof(D_list));
	if(new==NULL)
		return FAILURE;
	new->data=data;
	new->next=NULL;
	new->prev=NULL;
	if(*head==NULL)
	{
		*head=new;
		*tail=new;
		return SUCCESS;		
	}
	(*tail)->next=new;
	new->prev=*tail;
	*tail=new;
	return SUCCESS;
}

int Delete_list(D_list **head,D_list **tail)
{
	if(*head==NULL)
	{
		return FAILURE;
	}
	if(*head==*tail)
	{
		free(*head);
		*head=NULL;
		*tail=NULL;
		return SUCCESS;
	}
	while((*head)->next)
	{
		D_list *temp=*head;
		*head=(*head)->next;
		(*head)->prev=NULL;
		free(temp);
	}
	free(*head);    //Deallocating remaining last node
	*head=NULL;		//assigning head and tail to NULL
	*tail=NULL;
	return SUCCESS;
}

int copy(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2)
{
	Delete_list(head1,tail1);
	D_list *temp=*head2;
	while(temp)
	{
		insert_last(head1,tail1,temp->data);
		temp=temp->next;
	}
//	Delete_list(head2,tail2);
}

int Delete_last(D_list **head,D_list **tail)
{
	if(*head==NULL)
		return FAILURE;
	D_list *temp=*tail;
	*tail=(*tail)->prev;
	free(temp);
	return SUCCESS;
}

int Delete_first(D_list **head,D_list **tail)
{
	if(*head==NULL)
		return FAILURE;
	D_list *temp=*head;
	*head=(*head)->next;
	free(temp);
	return SUCCESS;
}
