//contributed by harsh vardhan
//implementation of tree using Linkedlist and Queue
//give input as -1 from empty node

#include<iostream>
#include<queue>
using namespace std;

// class for creating node of tree
class node
{
    public:
    node *lchild;
    int data;
    node *rchild;

    node(int val)
    {
        lchild=rchild=NULL;
        data=val;
    }
};

node *root=NULL;

// function to create binary tree
void create()
{
    node *temp;
    cout<<"give the value of root node :";
    int x;
    cin>>x;
    root=new node(x);
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        printf("give the value of left node of %d :",temp->data);
        cin>>x;
        if(x!=-1)
        {
            node *t=new node(x);
            temp->lchild=t;
            q.push(t);
        }
        printf("give the value of right node of %d :",temp->data);
        cin>>x;
        if(x!=-1)
        {
            temp=q.front();
            node *t=new node(x);
            temp->rchild=t;
            q.push(t);
        }
    }
   
}

// function for recursive preorder traversal
void preorder(node *t)
{
    if(t)
    {
        cout<<t->data<<' ';
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

//function for recursive inorder traversal
void inorder(node *t)
{
    if(t)
    {
        inorder(t->lchild);
        cout<<t->data<<' ';
        inorder(t->rchild);
    }
}

//function for recursive postorder traversal
void postorder(node *t)
{
    if(t)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<' ';
    }
}

//fouction for counting leaf_nodes
int count_leafnode(node *t)
{
    if(t==NULL)return 0;
    if(t)
    {
        if(t->lchild==NULL&&t->rchild==NULL)return 1;
    }

    return count_leafnode(t->rchild)+count_leafnode(t->lchild);;  
}

//function for counting all the nodes of tree
int count_nodes(node *t)
{
    if(t)
    {
        return count_nodes(t->lchild)+count_nodes(t->rchild)+1;
    }
    return 0;
}

//function for counting non-leaf nodes
int count_nonleafnode(node *t)
{
    if(t)
    {
        if(!t->lchild && !t->rchild) return 0;
    }
    return count_nonleafnode(t->lchild)+count_nonleafnode(t->rchild)+1;
}

//function for finding sum of all the element of teree
int sum(node *t)
{
    if(t)
    {
        return t->data+sum(t->lchild)+sum(t->rchild);
    }
    return 0;
}


int main()
{
    create();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<count_leafnode(root)<<endl;
    cout<<count_nodes(root)<<endl;
    cout<<count_nonleafnode(root)<<endl;
    cout<<sum(root)<<endl;
    return 0;
}
