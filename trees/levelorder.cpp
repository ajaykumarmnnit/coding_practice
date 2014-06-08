#include<iostream>
using namespace std;
struct Node{
int data;
struct Node *left, *right;
};
struct Node *newNode(int key)
{
struct Node *node= new Node();
node->data= key;
node->left=node->right= NULL;
return node;
}
int levelorder(struct Node *node , int level)
{
if(node== NULL)
return 0;
if(level == 2)
{

if(node->left!= NULL && node->right== NULL)
cout<<"Answer= "<<node->left->data<<endl;
else if(node->left== NULL &&	 node->right!= NULL)
cout<<"Answer= "<<node->right->data<<endl;
return 0;
}
levelorder(node->left, level-1);
levelorder(node->right, level-1);
}
int height(struct Node *node)
{
if(node == NULL)
return 0;

int lheight= height(node->left);
int rheight= height(node->right);
if(lheight>rheight)
    return lheight+1;
else
    return rheight+1;
}
void level(struct Node *node)
{
for(int i=2;i<=height(node);i++)
levelorder(node, i);
}
int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);
    level(root);
return 0;
}
