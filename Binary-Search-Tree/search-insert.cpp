#include<iostream>
using namespace std;
/*
Mostly in trees we use Recursion:
Here T.C if the tree is balanced:
            insertion: O(logn)
            search: O(logn)

*/
class BST_Node{
	public:
	int data;
	BST_Node* left;
	BST_Node* right;
};

BST_Node* insert(BST_Node* root,int ele)
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
bool search_ele(BST_Node*root,int ele)
{
	if(root==NULL)
	return false;
	if(root->data==ele)
	return true;
	else if(root->data>=ele)
	return search_ele(root->left,ele);
	else
	return search_ele(root->right,ele);
}

int main()
{
	int ele;
	BST_Node* root=NULL;
	root=insert(root,3);
	root=insert(root,1);
	root=insert(root,0);
	root=insert(root,2);
	cout<<"Enter the element to be searched:  "<<endl;
	cin>>ele;
	cout<<search_ele(root,ele)<<endl;
}
	
