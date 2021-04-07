#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	Node *link;
};
Node *head;
void insert(int a)
{
	Node *temp=(Node*)malloc(sizeof(struct Node));
	temp->data=a;
	temp->link=NULL;
		temp->link=head;
		head=temp;
}
void print()
{
	Node *temp=head;
	printf("Linked List is \n");
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->link;
		
	}
	printf("\n");
}
int main()
{
	head=NULL;
	int n,x;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	printf("Enter the element\n");
	scanf("%d",&x);
	insert(x);
	print();
}
}
