#include<stdio.h>
#include<stdlib.h>
struct Node
{
	Node* left;
	Node* right;
	int data;
};
Node *head=(Node*)malloc(sizeof(int));

// Insert at beginning
void insert(int x)
{
	Node* temp=(Node*)malloc(sizeof(int));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		head->left=temp;
		temp->right=head;
		head=temp;
	}
}


//Insertion at the end of list

void insertend(int y)
{
	Node* temp=(Node*)malloc(sizeof(int));
	temp->data=y;
	temp->left=NULL;
	temp->right=NULL;
	Node* temp1=head;
	while(temp1->right!=NULL)
	{
		temp1=temp1->right;
	}
	temp->left=temp1;
	temp1->right=temp;
	temp->right=NULL;
}
void print()
{
	Node*temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->right;
	}
	printf("\n");
}
int main()
{
	head=NULL;
	int n,x,y,m;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
		print();
	}
	printf("Enter the number of elements (Insertion at the end)\n");
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&y);
		insertend(y);
		print();
	}
	
}
