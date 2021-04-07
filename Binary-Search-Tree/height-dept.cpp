#include<iostream>
using namespace std;
/*
Height:
Maximum edges between a node and leaf node.
Height of empty tree= -1
Height of tree with 1 node=0
Height of tree=Height of root node

Dept:
Maximum edges between root and a node.
*/

int find_height(BST_Node* root)
{
	if(root==NULL)
	return -1;
	int left_height=find_height(root->left);
	int right_height=find_height(root->right);
	return max(left_height,right_height)+1;
}

