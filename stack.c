#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100
typedef struct Stack{
    int top;
    int arr[max];
}Stack; 
Stack * stack;
void init(){
    stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    printf("initialised\n");
}
bool isfull(){
    return stack->top==max-1;
}
bool isempty(){
    return stack->top==-1;
}
void push(int data){
    if(isfull()){
        printf("stack overflow\n");
    }
    else{
        stack->top++;
        stack->arr[stack->top]=data;
        printf("pushed\n");
    }
}
void pop(){
    if(isempty()){
        printf("stack underflow\n");
    }
    else{
        stack->top--;
        printf("poped\n");
    }
}
void display(){
    if(isempty()){
        printf("stack empty\n");
    }
    else{
        printf("stack: ");
        for(int i=0;i<stack->top+1;i++){
            printf("%d ",stack->arr[i]);
        }
    }
}
void main(){
    init();
    pop();
    display();
    push(10);
    push(20);
    push(40);
    display();   
}
