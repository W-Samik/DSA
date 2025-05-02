#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* head=NULL;
void inser_front(int data){
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=head;
    head=new;
}
void inser_btw(int data,int key){
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    if(head==NULL){
        head=new;
    }
    node* temp=head;
    node* prev=NULL;
    while(temp->data!=key && temp!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=new;
    new->next=temp;
}
void inser_last(int data){
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
void display(){
    if(head==NULL){
        printf("list is empty\n");
    }
    else{
        node* temp=head;
        printf("list : ");
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
void main(){
    inser_front(10);
    inser_front(20);
    inser_btw(30,10);
    inser_last(40);
    display();
}
