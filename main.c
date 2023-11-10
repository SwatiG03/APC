/*
Name		  : Swathi Gajaram
Date		  : 
Description   : 
Sample input  : 
Sample output : 
 */

#include "apc.h"

int sign1;	
int sign2; 
int	sign;

int main(int argc,char *argv[])
{
	D_list *head1,*head2,*head_R;
	head1=head2=head_R=NULL;
	D_list *tail1,*tail2,*tail_R;
	tail1=tail2=tail_R=NULL;
	if(argc==4)
	{
		list_create(argv,&head1,&tail1,&head2,&tail2);
		char oper=*argv[2];
		switch(oper)
		{
			case '+':
				{
					printf("Addition\n");
					if(sign1==0 && sign2==0)
						addition(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
					else if(sign1==1 && sign2==0)
					{
						if(strlen(argv[1]) == strlen(argv[3]))
						{
							if(strcmp(argv[1],argv[3])>=0)
							{
								sign=1;
								subtraction(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
							}
							else
							{
								subtraction(&head2,&tail2,&head1,&tail1,&head_R,&tail_R);
							}
						}
						else if(strlen(argv[1])<strlen(argv[3]))
						{
							subtraction(&head2,&tail2,&head1,&tail1,&head_R,&tail_R);
						}
						else
						{
							sign=1;
							subtraction(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
						}
					}
					else if(sign1==0 && sign2==1)
					{
						if(strlen(argv[1]) == strlen(argv[3]))
						{
							if(strcmp(argv[1],argv[3])>=0)
								subtraction(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
							else
							{
								sign=1;
								subtraction(&head2,&tail2,&head1,&tail1,&head_R,&tail_R);
							}
						}
						else if(strlen(argv[1])<strlen(argv[3]))
						{
							sign=1;
							subtraction(&head2,&tail2,&head1,&tail1,&head_R,&tail_R);
						}
						else
							subtraction(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
					}
					else
					{
						sign=1;
						addition(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
					}
				}
				break;
			case '-':
				{
					printf("Subtraction\n");
					if(sign1==0 && sign2==0)
					{
						if(strlen(argv[1]) == strlen(argv[3]))
						{
							if(strcmp(argv[1],argv[3])>=0)
								subtraction(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
							else
							{
								sign=1;
								subtraction(&head2,&tail2,&head1,&tail1,&head_R,&tail_R);
							}
						}
						else if(strlen(argv[1])<strlen(argv[3]))
						{
							sign=1;
							subtraction(&head2,&tail2,&head1,&tail1,&head_R,&tail_R);
						}
						else
							subtraction(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
					}
					else if(sign1==1 && sign2==0)
					{
						sign=1;
						addition(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
					}
					else if(sign1==0 && sign2==1)
					{
						addition(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
					}
					else
					{
						if(strlen(argv[1]) == strlen(argv[3]))
						{
							if(strcmp(argv[1],argv[3])>=0)
							{
								sign=1;
								subtraction(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
							}
							else
							{
								subtraction(&head2,&tail2,&head1,&tail1,&head_R,&tail_R);
							}
						}
						else if(strlen(argv[1])<strlen(argv[3]))
						{
							subtraction(&head2,&tail2,&head1,&tail1,&head_R,&tail_R);
						}
						else
						{
							sign=1;
							subtraction(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
						}
					}
				}
				break;
			case 'x':
				{
					printf("Multiplication\n");
					multiplication(&head1,&tail1,&head2,&tail2,&head_R,&tail_R);
					if((sign1==0 && sign2==0) || (sign1==1 && sign2==1))
						sign=0;
					else if((sign1==1 && sign2==0) || (sign1==0 && sign2==1))
						sign=1;
					
				}
				break;
			case '/':
				{
					printf("Division\n");
					int count;
					if(head2->next==NULL && head2->data==0)
					{
						printf("Infinity\n");
						return 0;
					}
					if((sign1==0 && sign2==0) || (sign1==1 && sign2==1))
						sign=0;
					else if((sign1==1 && sign2==0) || (sign1==0 && sign2==1))
						sign=1;
					if(strlen(argv[1]) >= strlen(argv[3]))
					{
						if(strcmp(argv[1],argv[3])>=0)
						{
							if((count=division(&head1,&tail1,&head2,&tail2,&head_R,&tail_R)))
								insert_last(&head_R,&tail_R,count);
							else
								printf("Failure in Division\n");
						}
						else
						{
							sign=0;
							insert_last(&head_R,&tail_R,0);
						}
					}	
					else
					{
						sign=0;
						insert_last(&head_R,&tail_R,0);
					}
				}
				break;
			default:
				printf("Invalid operator Pass + - / *\n");
		}
		if(sign==1 && (head_R->next!=NULL && head_R->data!=0))
			printf("-");
		print_list(head_R);
	}
	else
		printf("Error in passing arguments: \n./a.out <operand1> <operator> <operand2>\n");
	return 0;
}











