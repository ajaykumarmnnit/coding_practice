#include<stdio.h>
#include<stdlib.h>
#include"tree_basic.h"

//Utility function for BST Tree creation
TREE* insert(TREE* root,TREE* temp)
{
	if(!root)
		return temp;
	if(root->val < temp->val)
		root->right=insert(root->right,temp);	  	
	else 
		root->left=insert(root->left,temp);
	return root;
}

//Creates a BST Tree
TREE* create_new_tree()
{
	int v;
	TREE *temp,*root;
	temp=root=NULL;
	scanf("%d",&v);
	while(v!=0)
	{
		temp=(TREE*)malloc(sizeof(TREE));
		temp->right=NULL;
		temp->left=NULL;
		temp->val=v;
		root=insert(root,temp);
		scanf("%d",&v);
	}
	return root;
}

//Prints PreOrderr Traversal of a tree
void preorder(TREE* root)
{
	if(root)
	{
		printf("%d ",root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

//Prints Inorder Traversal of a tree
void inorder(TREE* root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}

//Prints PostOrder Traversal of a tree
void postorder(TREE* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->val);
	}
}
