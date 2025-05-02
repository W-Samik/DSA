#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}node;
node* head=NULL;
void inser_front(int data){
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->right=NULL;
    new->left=NULL;
    if(head==NULL){
        head=new;
    }
    else{
        node* temp=head;
        head=new;
        head->right=temp;
        temp->left=new;
    }
    printf("inserted\n");
}
void inser_btw(int data,int key){
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->right=NULL;
    new->left=NULL;
    if(head==NULL){
        head=new;
    }
    else{
        node* temp=head;
        node* prev=NULL;
        while(temp->data!=key && temp!=NULL){
            prev=temp;
            temp=temp->right;
        }
        prev->right=new;
        new->left=prev;
        new->right=temp;
        temp->left=new;
    }
}
void inser_last(int data){
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->right=NULL;
    new->left=NULL;
    if(head==NULL){
        head=new;
    }
    else{
        node* temp=head;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->right=new;
        new->left=temp;
    }
}
void display(){
    if(head==NULL){
        printf("list is empty\n");
    }
    else{
        node* temp=head;
        printf("list: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->right;
        }
        printf("\n");
    }
}
void main(){
    inser_front(10);
    inser_front(20);
    inser_btw(30,10);
    inser_last(40);
    display();
}