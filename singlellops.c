#include <stdio.h>
#include <stdlib.h>
struct node{
    int item;
    struct node* next;
};

struct node* head=NULL;

void display(){
    if(head==NULL){
        printf("List is empty");
    }
    else{
        printf("Elements in the linked list :\n");
        struct node* temp=head;
        while(temp!=NULL){
            if(temp->next==NULL){
                printf("%d",temp->item);
            }
            else{
                printf("%d-> ",temp->item);
                
            }
            temp=temp->next;
        }
    }
}

void insbeg(int element){
    struct node* newnode=(struct node*)malloc(sizeof( struct node));;
    newnode->item=element;
    newnode->next=head;
    head=newnode;
}

void insend(int element){
    struct node* temp;
    temp=head;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->item=element;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void ins(int element,int posn){
    struct node* newnode;
    struct node* temp ;
    newnode->next=NULL;
    newnode->item=element;
    int i=1;
    temp = head;
    while(i<posn-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void delbeg(){
    struct node* temp;
    temp=head;
    head=head->next;
    free(temp);
}

void delend(){
    struct node* temp;
    struct node* prev;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=NULL;
}

void del(int posn){
    struct node* temp;
    struct node* deleted;
    deleted=malloc(sizeof(struct node));
    int i=1;
    temp=head;
    while(i<posn-1){
        temp=temp->next;
        i++;
    }
    deleted=temp->next;
    temp->next=deleted->next;
    free(deleted);
}

int main(){
    char input;
    int element,posn;
    while(1){
        scanf("%c",&input);
        switch((int)input){
            case 10:
            break;
            case 97:
            display();
            break;
            case 98:
            scanf("%d",&element);
            insbeg(element);
            break;
            case 99:
            scanf("%d",&element);
            insend(element);
            break;
            case 100:
            scanf("%d",&posn);
            scanf("%d",&element);
            ins(element,posn);
            break;
            case 101:
            delbeg();
            break;
            case 102:
            delend();
            break;
            case 103:
            scanf("%d",&posn);
            del(posn);
            break;
            default:
            printf("!!! ERROR !!!");
            break;
        }
    }
    return 0;
}

