#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	Node* link;
};
Node *head;
void insert(int v,int i)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=v;
	temp->link=NULL;
	if(i==1)
	{
		temp->link=head;
		head=temp;
		return;
	}
	else
	{
		Node *temp1=head;
		for(int k=0;k<i-2;k++)
		{
			temp1=temp1->link;
		}
		temp->link=temp1->link;
		temp1->link=temp;
		
	}
}
void print()
{
	Node *temp2=head;
	while(temp2!=NULL)
	{
		printf("%d  ",temp2->data);
		temp2=temp2->link;
	}
}
int main()
{
	head=NULL;
	int n,a,b;
	printf("Enter the number of elements you want to insert\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the element and index\n");
		scanf("%d %d",&a,&b);
		insert(a,b);
		print();
	}
}

