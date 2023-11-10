#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
}D_list;


int addition(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2,D_list **head_R,D_list **tail_R);
int subtraction(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2,D_list **head_R,D_list **tail_R);
int multiplication(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2,D_list **head_R,D_list **tail_R);
int division(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2,D_list **head_R,D_list **tail_R);

int list_create(char *argv[],D_list **head1,D_list **tail1,D_list **head2,D_list **tail2);
void print_list(D_list *head);
int insert_first(D_list **head,D_list **tail,int data);
int insert_last(D_list **head,D_list **tail,int data);
int Delete_list(D_list **head,D_list **tail);
int Delete_first(D_list **head,D_list **tail);
int Delete_last(D_list **head,D_list **tail);
int copy(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2);
int compare(D_list **head1,D_list **tail1,D_list **head2,D_list **tail2);
#endif
