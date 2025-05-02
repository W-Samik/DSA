#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* head=NULL;
void push(int data){
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    if(head==NULL){
        head=new;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
}
void pop(){
    if(head==NULL){
        printf("stack underflow\n");
    }
    else{
        node* temp=head;
        node* prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
    }
}
void display(){
    if(head==NULL){
        printf("stack underflow\n");
    }
    else{
        node* temp=head;
        printf("stack: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void main(){
    pop();
    push(10);
    push(20);
    display();
    pop();
    display();
}