#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	Node *left;
	Node *right;
};
Node *head;


void insert_at_begin(int ele){
	
	Node *temp=(Node*)malloc(sizeof(Node));
	
	temp->data=ele;
	temp->left=NULL;

	if(head==NULL)
	{
	temp->right=NULL;
	head=temp;
	}
	else
	{
		temp->right=head;
		head->left=temp;
		head=temp;
	}
	
}


void insert_at_end(int ele)
{
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=ele;
	temp->right=NULL;
	if(head==NULL)
	{
		temp->left=head;
		head=temp;
	}
	else{
		Node* traverse=head;
		while(traverse->right!=NULL){
			
			traverse=traverse->right;
		}
		traverse->right=temp;
		temp->left=traverse;
	}
	
}

void reverse_print()
{
	Node* temp=head;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->left;
	}
}

void print(){
	Node *temp=head;
	
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->right;
		
	}
}
int main(){
	int n,ele,i;
	printf("Enter the number of elements  ");
	scanf("%d",&n);
	/*printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ele);
		insert_at_begin(ele);
	}
	printf("\nWhen element inserted in the beginning..\n");
	print();
	*/
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ele);
		insert_at_end(ele);
	}
	printf("\nWhen element inserted in the end..\n");
	print();
	printf("\nPrinting in reverse order..\n");
	reverse_print();
	
	
}
