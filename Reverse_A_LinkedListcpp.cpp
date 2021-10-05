#include<bits/stdc++.h>
using namespace std;


class Node{
public:
 int data;
 Node* next;
 Node(int value){
  data=value;
 }
};

Node *reverse(Node *head){
  if(head==NULL || head->next==NULL)
    return head;

    Node *newhead=reverse(head->next);
    head->next->next=head;
    head->next=NULL; 

    return newhead;
}

void print(Node *head){
  while(head!=NULL){

      cout<<head->data;
      if(head->next!=NULL)
        cout<<"->";
    
    head=head->next;

  }
}


int main(){
  Node *t=new Node(1);
  Node *head=t;
  for(int i=2;i<=10;i++){ 
    t->next=new Node(i);
    t=t->next;
  }
  t->next=NULL;
  cout<<"The old linked list is: ";
  print(head); // This will print the old linked list
cout<<"\n";
Node *newhead=reverse(head); // This function basically reverses the linked list

cout<<"\n";
cout<<"The new linked list after reversing : ";
print(newhead);    // This function prints the new linked list after reversing the linked list.


}