#include<iostream>
using namespace std;
/*
Leftmost element is min
Righmost element is max
/*
class BST_Node{
	public:
		int data;
		BST_Node* left;
		BST_Node* right;
};

class BST{
	public:
		BST_Node* insert(BST_Node* root,int ele)
		{
			BST_Node* b=new BST_Node();
			b->data=ele;
			b->left=NULL;
			b->right=NULL;
			
			if(root==NULL)
			root=b;
			
			else
			{
				if(ele<root->data)
				root->left=insert(root->left,ele);
				else
				root->right=insert(root->right,ele);
			}
			return root;
	
		}
		int find_min_recursive(BST_Node* root)
		{	
			if(root==NULL)
				return -1;
			else if(root->left==NULL)
				return root->data;
			return find_min_recursive(root->left);
		}
		
		int find_max_recursive(BST_Node* root)
		{	
			if(root==NULL)
				return -1;
			else if(root->right==NULL)
				return root->data;
			return find_max_recursive(root->right);
		}


		int find_min_iterative(BST_Node* root)
		{
			while(root->left!=NULL)
			root=root->left;
			return root->data;
		}

		int find_max_iterative(BST_Node* root)
		{
			while(root->right!=NULL)
			root=root->right;
			return root->data;
		}
		
};

int main()
{
	BST_Node* root=new BST_Node();
	root=NULL;
	BST b;
	int n;
	cout<<"Enter the number element you want to insert :"<<endl;
	cin>>n;
	cout<<"Now enter the element"<<endl;
	for(int i=0;i<n;i++)
	{
		int ele;
		cin>>ele;
		root=b.insert(root,ele);
	}
	cout<<root->right->right->data<<endl;
	int min_ele=b.find_min_recursive(root);
	cout<<"Min element is: "<<min_ele<<endl;
	
	int max_ele=b.find_max_recursive(root);
	cout<<"Max element is: "<<max_ele;
	
	
}
