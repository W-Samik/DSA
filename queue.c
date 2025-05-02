#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100
typedef struct Queue{
    int front,rear;
    int arr[max];
}Queue;
Queue* queue;
void init(){
    queue=(Queue*)malloc(sizeof(Queue));
    queue->front=-1;
    queue->rear=-1;
    printf("initiLISED\n");
}
bool isempty(){
    return queue->front==-1||queue->front > queue->rear;
}
bool isfull(){
    return queue->rear==max-1;
}
void enqueue(int data){
    if(isfull()){
        printf("queue overflow\n");
    }
    else{
        if(queue->front==-1)
            queue->front=0;
        queue->rear++;
        queue->arr[queue->rear]=data;
        printf("enqueued\n");
    }
}
void dequeue(){
    if(isempty()){
        printf("queue underflow\n");
    }
    else{
        queue->front++;
        printf("dequeued\n");
    }
}
void display(){
    if(isempty()){
        printf("queue empty\n");
    }
    else{
        printf("queue: ");
        for(int i=queue->front;i<queue->rear+1;i++){
            printf("%d ",queue->arr[i]);
        }
        printf("\n");
    }
}
void main(){
    init();
    dequeue();
    display();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
}
