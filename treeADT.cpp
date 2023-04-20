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

node* min(node *root)
{
  node *temp=root;
  while(temp->left!=NULL)
  {
   temp=temp->left;
  }
  return temp;
}
node* max(node *root)
{
  node *temp=root;
  while(temp->right!=NULL)
  { 
   temp=temp->right;
  }
  return temp;
}
void insertBST(node *root,int data)
{
 while(root->left!=NULL || root->right!=NULL)
 {
  if(data>root->info)
  {
   root=root->right;
  }
  if(data<root->info)
  {
  root=root->left;
  }
 } 
  node *ptr=create(data);
   if(data>root->info)
  {
   root->right=ptr;
  }
  if(data<root->info)
  {
  root->left=ptr;
  }
}
node* deleteBST(node *root,int key)
{
   if(root==NULL)
  {
    return root;
  }
  else if(key>root->info)
  {
   root->right=deleteBST(root->right,key);
  }
  else if(key<root->info)
  {
  root->left=deleteBST(root->left,key);
  }
 
  else
{
  if(root->right==NULL)
  {
   node *temp=root->left;
   free(root);
   return temp;
  }
 else if(root->left==NULL)
  {
   node *temp=root->right;
   free(root);
   return temp;
  }
   node *temp=max(root->right);
   root->info=temp->info;
   root->right=deleteBST(temp,temp->info);
 }
  return root;
}
int isBST(node *root,node *min=NULL,node *max=NULL)
{
 if(root==NULL)
 {
  return 1;
 }
 if(min!=NULL && root->info <= min->info)
 {
  return 0;
 }
 if(max!=NULL && root->info>=max->info)
 {
  return 0;
  }
 int l=isBST(root->left,min,root);
 int r=isBST(root->right,root,max);
 return l && r;
}
void search(node *root,int key)
{
 while(root->info!=key)
{
  if(key>root->info)
{
  root=root->right;
}
  else
 {
   root=root->left;
 }
}
  cout<<" searched  data=>> "<<root->info<<endl;
}
int main()
{
    //pending
     node *root;
      root=create(00);
     int cmd,data,key,key2;
    while(1)
    {
     clrscr();
     cout<<"||======================||"<<endl;
     cout<<"|| +------------------+ ||"<<endl;
     cout<<"|| |      TREE        | ||"<<endl;
     cout<<"|| +------------------+ ||"<<endl;
     cout<<"||======================||"<<endl;
     cout<<endl;  
     cout<<"PREORDER --->>";
     preorder(root);
     cout<<"]";
     cout<<endl;
     cout<<"INORDER --->>";
     inorder(root);
     cout<<"]";
     cout<<endl;
     cout<<"POSTORDER --->>";
     postorder(root);
     cout<<"]";
     cout<<endl<<endl;
     cout<<"1.insert data"<<endl;
     cout<<"2.delete data"<<endl;
     cout<<"3.search"<<endl;
     cout<<"4.max "<<endl;
     cout<<"5.min"<<endl;
     cout<<"6.exit"<<endl;
     cout<<"enter the command =>> "<<endl;
     cin>>cmd;
     switch(cmd)
     {
      case 1:
      cout<<"enter the data=>>"<<endl;
      cin>>data;
      insertBST(root,data);
      break;
      case 2:
      cout<<"enter the key=>>"<<endl;
      cin>>key;
      deleteBST(root,key);
      break;
      case 3:
      cout<<"enter the key =>>"<<endl;
      cin>>key2;
      search(root,key2);
      getch();
      break;
      case 4:
      cout<<max(root)->info;
      getch();
      break;
      case 5:
      cout<<min(root)->info;
      getch();
      break;
      case 6:
      return 0;
      break;
      default:
      cout<<"command is not found"<<endl;
      break;
     }
      getch();
    }
     
    return 0;
}