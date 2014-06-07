#include<stdio.h>
#include"tree_basic.c"

int max(int x,int y) { return (x>y)?x:y;}

void level_order(TREE* node , int level)
{
	if(node== NULL)
		return;
	if(level == 1)
	{
		printf("%d ",node->val);
		return;
	}
	else
	{
		level_order(node->left, level-1);
		level_order(node->right, level-1);
	}
}

int height(TREE* node)
{
	if(node == NULL)
		return 0;
	return (1+ max(height(node->left), height(node->right)) );
}

void levelorder(TREE* node)
{
	int i,h=height(node);
	for(i=1;i<=h;i++)
		level_order(node, i);
}
