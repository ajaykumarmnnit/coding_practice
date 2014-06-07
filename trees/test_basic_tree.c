#include<stdio.h>
#include"tree_basic.h"

int main()
{
	TREE* root;
	root=create_new_tree();
	printf("PreOrder: ");
	preorder(root);
	printf("\nInOrder: ");
	inorder(root);
	printf("\nPostOrder: ");
	postorder(root);
	printf("\n");

	return 0;
}
