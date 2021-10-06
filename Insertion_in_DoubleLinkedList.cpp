// INSERTION IN BETWEEN
// INPUT THE FIRST VARIABLE WITH NUM TO BE INSERTED
// AND THE SECOND INPUT TO SPECIFY AFTER WHICH NUM
// THE INPUT NUM IS TO BE INSERTED 
#include <iostream>
using namespace std;
struct node{
    int data;
    node *ptr,*pre;
};
node *head=NULL;
void insertathead(int a){
    node *p=new node;
    p->data=a;
    p->pre=p->ptr=NULL;
    if(head==NULL){
        head=p;
    }
    else{
        head->pre=p;
        p->ptr=head;
        head=p;
    }
}
void insertioninbetween(int a,int b){
    node *p=new node;
    p->data=a;
    p->pre=p->ptr=NULL;
    if(head==NULL)
        p=head;
    else {
    node *temp=head;
        while(temp && temp->data!=b){
            temp=temp->ptr;
        }
        if(temp==NULL){
            cout<<"ELEMENT NOT FOUND\n";
            temp=p=NULL;
        }
        else if(temp->ptr==NULL){
            p->pre=temp;
            temp->ptr=p;
        }
        else{
            p->pre=temp;
            p->ptr=temp->ptr;
            temp->ptr->pre=p;
            temp->ptr=p;
        }   
    }
}
void displayfromhead(){
    node *p=head;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->ptr;
    }
}
int main()
{
    insertathead(50);    
    insertathead(40);    
    insertathead(30);    
    insertathead(20);    
    insertathead(10);    
    cout<<"BEFORE INSERTION\n";
    displayfromhead();
    insertioninbetween(500,30);
    insertioninbetween(100,20);
    cout<<"AFTER INSERTION\n";
    displayfromhead();
    return 0;
}
