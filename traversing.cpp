#include<iostream>
#include<stdio.h>
#include<conio.h>
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
void preorder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        cout<<root->info<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        inorder(root->left);
        cout<<root->info<<" ";
        inorder(root->right);
    }
}
void postorder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->info<<" ";
    }
} 
int main()
{
    clrscr();
    node *root,*p1,*p2,*p3,*p4;
    root=create(40);
    p1=create(20);
    p2=create(50);
    p3=create(10);
    p4=create(30);
   
    root->left=p1;
    root->right=p2;
  
    p1->left=p3;
    p1->right=p4;
    cout<<"preorder"<<endl;
    preorder(root);
    cout<<endl<<endl;
    cout<<"inorder"<<endl;
    inorder(root);
    cout<<endl<<endl;
    cout<<"postorder"<<endl;
    postorder(root);
    return 0;
}