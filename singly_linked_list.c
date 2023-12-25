#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
// for front insertion 
struct node *insertfront(struct node *head, int data){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    if(head==NULL){
        return newnode;
    }
    else
    newnode->next= head;
    head=newnode;
    return head;
}
// for end insertion 
void insertend(struct node *head, int data){
    struct node *newnode,*temp=head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
     newnode->next=NULL;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     temp->next=newnode;
}
// for any position insertion
void insertpos(struct node *head, int data, int pos){
    int i=1;
    struct node *temp=head,*newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
// node deleting from front 
struct node *deletefront(struct node *head){
    struct node *temp=head;
     
    head=head->next;
   
    free(temp);
    return head;
}
// node deleting from end  
void deleteend(struct node *head){
    struct node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
}
 // node deleting from a position 
void deletepos(struct node *head, int pos){
    struct node *temp=head,*p=head->next;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
        p=p->next;
    }
    temp->next=p->next;
    free(p);
}
// to reverse linked list
struct node *reverse(struct node *head){
    struct node *pre=NULL,*present;
    struct node *after;
    after=present= head;
    while(present!=NULL){
        after=present->next;
        present->next=pre;
        pre=present;
        present=after;
    }
    return pre;
}
// to search node value at any position 
void print(struct node *head, int pos){
    struct node *temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    printf("\nyour searched position node data is %d\n",temp->data);
}
// to display output 
void display(struct node *head){
    struct node *temp=head;
    if(head==NULL){
        printf("\n linked list is empty\n");
        return;
    }
    while(temp!=NULL){
        printf(" %d ", temp->data);
        temp=temp->next;
    }
    
}
// main function for starting 
int main(){
    struct node *head=NULL;
    
    head= insertfront(head, 2);
     head= insertfront(head, 4);
     head= insertfront(head, 6);
     head= insertfront(head, 8);
     head= insertfront(head, 10);
     head= insertfront(head, 14);
     head= insertfront(head, 16);
    printf("\n initial linked list is \n");
    display(head);  // display initially linked list
    
    insertend(head,25);
    insertend(head,50);
    insertend(head,75);
    printf("\nlinked list after end insertion \n");
    display(head);  // display end deleted linked list
    
    insertpos(head,100,3);
    insertpos(head,200,5);
    printf("\n position inserted linked is \n");
    display(head);  // display at position inserted
    
    head=deletefront(head);
     head=deletefront(head);
    printf("\n front deleted linked list is \n");
    display(head); // front deleted display
    
    deleteend(head);
     printf("\n end deleted linked list is \n");
    display(head); // end deleted display
    
    deletepos(head,4);
     printf("\n position deleted linked list is \n");
    display(head);  // position deleted display
    
    head=reverse(head);
    printf("\n reversed linked list is \n");
    display(head);  //reverse display
    
    print(head,5); // search data at a specific position
    return 0;
}
