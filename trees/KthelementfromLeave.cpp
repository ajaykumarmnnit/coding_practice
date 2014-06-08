#include<iostream>
using namespace std;
int check=0;
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
int print(struct Node *node, int count)
{
if(node== NULL)
{
cout<<"node== NULL"<<" count= "<<count<<" check= "<<check<<endl;
check= count-1	;
return 0;
}
else
{
print(node->left, count+1);
cout<<"Left::node= "<<node->data<<" count= "<<count<<" check= "<<check<<endl;
if(count == check-2)
{
cout<<"count == check-1"<<" count= "<<count<<" check= "<<check<<endl;
cout<<" Answer= "<<node->data<<endl;
}
print(node->right, count+1);
cout<<"Right::node= "<<node->data<<" count= "<<count<<" check= "<<check<<endl;
}
if(count == check-2)
{
cout<<"count == check-1"<<" count= "<<count<<" check= "<<check<<endl;
cout<<" Answer= "<<node->data<<endl;
}
}
int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
 //   root->right->left->left = newNode(9);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    print(root,0);
return 0;
}
