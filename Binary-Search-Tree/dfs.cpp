#include <iostream>
#include <queue>
using namespace std;
class BST_Node{
	public:
	char data;
	BST_Node* left;
	BST_Node* right;
};
BST_Node* insert(BST_Node* root,char ele)
{
	if(root==NULL)
	{
	BST_Node* n=new BST_Node();
	n->data=ele;
	n->left=NULL;
	n->right=NULL;
	root=n;
	}
	else if(ele<=(root->data))
	{
		root->left=insert(root->left,ele);
	}
	else
	{
		root->right=insert(root->right,ele);
	}
	return root;
	
}
void preorder_traversal(BST_Node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

void in_traversal(BST_Node* root)
{
	if(root==NULL)
	return;
	in_traversal(root->left);
	cout<<root->data<<" ";
	in_traversal(root->right);
}

void post_traversal(BST_Node* root)
{
	if(root==NULL)
	return;
	post_traversal(root->left);
	post_traversal(root->right);
	cout<<root->data<<" ";
}
int main()
{
	int n;
	char ele;
	cout<<"Enter the number of elements: "<<endl;
	cin>>n;
	cout<<"Enter the elements: "<<endl;
	BST_Node* root=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		root=insert(root,ele);
	}
	cout<<"\nPRE-ORDER TRAVERSAL:    ";
	preorder_traversal(root);
	cout<<"\nIN-ORDER TRAVERSAL:    ";
	in_traversal(root);
	cout<<"\nPOST-ORDER TRAVERSAL:    ";
	post_traversal(root);
}
