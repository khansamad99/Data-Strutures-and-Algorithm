#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;

};
struct node* newNode()
{
  int d;
  printf("Enter the value at node\n");
  scanf("%d",&d);
  struct node* n1 = (struct node*)malloc(sizeof(struct node));
  if(d==-1)
  {
      return NULL;
  }
  n1->data = d;
  n1->left = newNode();
  n1->right = newNode();

  return(n1);
}
void printNode(struct node *root)
{
    printf("%d ",root->data);
    printNode(root->left);
    printNode(root->right);
}
int main()
{
  struct node *root = newNode();
  printNode(root);
}
