#include "apc.h"
extern int sign1;
extern int sign2;
int list_create(char *argv[],D_list **head1,D_list **tail1,D_list **head2,D_list **tail2)
{
	int i=0;
	if(argv[1][0]=='-')
	{
		sign1=1;
		*(argv+1)=*(argv+1)+1;
	}
	while(argv[1][i])
	{
		if(insert_last(head1,tail1,argv[1][i]-48)==SUCCESS)
			i++;
	}	
	i=0;
	if(argv[3][0]=='-')
	{
		sign2=1;
		*(argv+3)=*(argv+3)+1;
	}
	while(argv[3][i])
	{
		if(insert_last(head2,tail2,argv[3][i]-48)==SUCCESS)
			i++;
	}
	return SUCCESS;	
}
