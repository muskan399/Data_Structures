#include<iostream>
using namespace std;
/*
Find Inorder(sorted) succesor: 1,2,3,4,5( Here 3 is inorder successor of 2)
T.C: O(h), h is the height of the tree

Approach1:
Traverse the tree but T.C is O(N), N is the number of nodes.

Approach2 (Better):
2 cases:
-> If right child is NULL: Then the deepest left ancestor is the inorder succesor
-> If right child is not NULL: Then find the min element in the left subtree.
T.C is O(h)

*/
class Node{
	public:
	int data;
	Node* left;
	Node* right;
};
Node* find(Node* root,int ele)
{
	Node* temp=root;
	Node* current=NULL;
	while(temp->data!=ele)
	{
		if(temp->data<ele)
		temp=temp->right;
		else
		temp=temp->left;
	}
	return temp;
}
Node* find_min(Node* d)
{
	while(d->left!=NULL)
	{
		d=d->left;
	}
	return d;
}
Node* find_ancestor(Node* root,Node* d)
{
	Node* temp=root;
	Node* c=NULL;
	while(temp!=d)
	{
		if((temp->data)<d->data)
		{
			temp=temp->right;
		}
		else
		{
			c=temp;
			temp=temp->left;
		}
	}
	return c;
}

Node* find_inorder_successor(Node* root,int data)
{
	Node* d=find(root,data);
	Node* a=NULL;
	if(d->right!=NULL)
	{
		a=find_min(d->right);
		
	}
	else
	{
		a=find_ancestor(root,d);
		
	}
	return a;
}
Node* insert(Node* root,int d)
{
	if(root==NULL)
	{
		Node* temp=new Node();
		temp->data=d;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
	}
	else if((root->data)<d)
		root->right=insert(root->right,d);
	else
	root->left=insert(root->left,d);
	return root;
}

int main()
{
	int n;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	Node* root=NULL;
	for(int i=0;i<n;i++)
	{
		int ele;
		cin>>ele;
		root=insert(root,ele);
	}
	cout<<"Enter the number whose Inorder Sucessor we have to find: "<<endl;
	int e;
	cin>>e;
	Node* a=find_inorder_successor(root,e);
	cout<<a->data<<endl;
	
}
