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
void inorder_traversal(BST_Node* root)
{
	if(root==NULL)
	return;
	queue< BST_Node* > q;
	q.push(root);
	//cout<<root->data<<endl;
	while(!q.empty())
	{
		BST_Node* current=q.front();
		cout<<current->data<<" ";
		if(current->left!=NULL)
		q.push(current->left);
		if(current->right!=NULL)
		q.push(current->right);
		q.pop();
	}
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
	inorder_traversal(root);
}
