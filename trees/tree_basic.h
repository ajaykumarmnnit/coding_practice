typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
}TREE;

TREE* create_new_tree();
TREE* insert(TREE* ,TREE*);
void preorder(TREE*);
void inorder(TREE*);
void postorder(TREE*);
