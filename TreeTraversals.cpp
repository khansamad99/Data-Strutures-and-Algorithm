#include<iostream>
using namespace std;

class node
 {
   public:
        int data;
        node *left;
        node *right;

        node(int d)
        {
          data = d;
          left = NULL;
          right = NULL;
        }

 };

 node *buildTree()
 {
   int d;
   cin>>d;

   if(d==-1)
   {
     return NULL;
   }

   node *root = new node(d);
   root->left = buildTree();
   root->right = buildTree();
   return root;
 }

 void printPreorder(node *root)
 {
   if(root == NULL)
   return;

   cout<<root->data<<" ";
   printPreorder(root->left);
   printPreorder(root->right);

 }
 void printInorder(node *root)
 {
   if(root == NULL)
   return;

   printInorder(root->left);
   cout<<root->data<<" ";
   printInorder(root->right);

 }
 void printPostorder(node *root)
 {
   if(root == NULL)
   return;

   printPostorder(root->left);
   printPostorder(root->right);
   cout<<root->data<<" ";

 }
 int height(node *root)
 {
   if(root==NULL)
   {
      return 0;
   }

   int ls = height(root->left);
   int rs = height(root->right);

   return max(ls,rs) + 1;
 }
 void printkthLevel(node *root,int k)
 {
   if(root == NULL)
   {
     return ;
   }
    if(k==1)
    {
     cout<<root->data<<" ";
     return ;
    }

    printkthLevel(root->left,k-1);
    printkthLevel(root->right,k-1);

 }
 void printAllLevels(node *root)
 {
   int h = height(root);
   for(int i=1;i<=h;i++)
   {
     printkthLevel(root,i);
   }
 }
 int main()
 {
    node *root = buildTree();
    cout<<"Preorder Traversal of Tree\n";
    printPreorder(root);
    cout<<"\nInorder Order Traversal of Tree\n";
    printInorder(root);
    cout<<"\nPostOrder Traversal of Tree\n";
    printPostorder(root);
    cout<<"\nHeight of Tree\n";
    cout<<height(root);
    cout<<"\nLevel order Traversal Of Tree\n";
    printAllLevels(root);
 }

