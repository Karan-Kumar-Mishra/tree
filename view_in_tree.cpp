#include<iostream>
#include<stdio.h>
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
    ptr->left=ptr->right=NULL;
    return ptr;
}
node* left_view(node *ptr)
{
    if(ptr==NULL)
    {
        return ptr;
    }
    cout<<ptr->info<<" ";
    left_view(ptr->left);
}
node* right_view(node *ptr)
{
    if(ptr==NULL)
    {
        return ptr;
    }
    cout<<ptr->info<<" ";
    right_view(ptr->right);
}
int main()
{
    node *p1,*p2,*p3,*p4,*p5,*p6,*p7;

    p1=create(10);
    p2=create(20);
    p3=create(30);
    p4=create(40);
    p5=create(50);
    p6=create(60);
    p7=create(70);

    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->left=p6;
    p3->right=p7;
    cout<<"left view :"<<endl;
    left_view(p1);
    cout<<endl;
    cout<<"right view :"<<endl;
    right_view(p1);

    /*
           10
          /  \
         /    \
        20     30
       /  \    / \
      40   50 60  70

     1.left view output :10,20,40
     2.right view output: 10,30,70

    */
    return 0;
}