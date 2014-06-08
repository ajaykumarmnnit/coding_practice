#include<iostream>
#include<vector>
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
int commonancestor(struct Node *node, vector<int> &path, int searchnode)
{
if(node == NULL )
return 0;
path.push_back(node->data);
if(node->data ==searchnode)
return 1;
if(commonancestor(node->left,path,searchnode))
return 1;
if(commonancestor(node->right,path,searchnode))
return 1;
path.pop_back();
return 0;
}
int main()
{
    int node1=8,node2=7;
    vector<int> path1 ,path2;
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    commonancestor(root,path1,node1);
    commonancestor(root,path2,node2);
    for(int i=0;i< path1.size() && i< path2.size();i++)
     {
       if(path1[i]!=path2[i])
        {
         cout<<""<<path1[i-1];
         break;
        }

     }
return 0;
}
