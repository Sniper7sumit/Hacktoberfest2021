#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *ptr;
};
struct node *head=NULL;


void insert(int a){
node *temp=new node;
temp->data=a;
temp->ptr=NULL;
if(head==NULL)
head=temp;
else{
    node *temp1=head;
    while(temp1->ptr!=NULL)
     temp1=temp1->ptr;
    temp1->ptr=temp;
}
};  

void display(){
 if(head){
    node *p=head;
    while(p!=NULL){
        cout<<"Data is :"<<p->data<<endl;
        p=p->ptr;
    }
}
else 
cout<<"Empty Linked List";
}

int main(){
insert(10);
insert(20);
insert(30);
insert(40);
display();
return 0;
}
