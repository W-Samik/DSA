#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* head=NULL;
void enqueue(int data){
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
    printf("psuhed\n");
}
void dequeue(){
    if(head==NULL){
        printf("queue underflow\n");
    }
    else{
        head=head->next;
    }
}
void display(){
    if(head==NULL){
        printf("queue is empty\n");
    }
    else{
        node* temp=head;
        printf("queue: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void main(){
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
}