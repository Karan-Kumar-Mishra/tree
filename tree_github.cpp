#include<iostream>
using namespace std;
class node
{
  public:
  int info;
  node *left;
  node *right;
};
node* create(int data)
{
  node *ptr= new node;
  ptr->info=data;
  ptr->left=NULL;
  ptr->right=NULL;
  return ptr;
}
node* inorder(node *root)
{
 if(root==NULL)
 {
  return root;
 }
 else
 {
  inorder(root->left);
  cout<<root->info<<" ";
  inorder(root->right);
 }
}
int main()
{
    node *root,*n1,*n2,*n3,*n4;
    root=create(10);
    n1=create(20);
    n2=create(30);
    n3=create(40);
    n4=create(50);
     
    root->left=n1;
    root->right=n2;
    
    n1->left=n3;
    n1->right=n4;
    inorder(root);
    return 0;
}