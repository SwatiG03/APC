#include "apc.h"

void print_list(D_list *head)
{
	if(head==NULL)
		printf("List Empty\n");
	while(head)
	{
		printf("%d",head->data);
		head=head->next;
	}
	printf("\n");
}
