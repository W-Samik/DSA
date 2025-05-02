#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100

typedef struct Queue{
    int rear,front;
    int arr[max];
}Queue;

Queue* queue;
int size=sizeof(Queue*);

void init(){
    queue=(Queue*)malloc(sizeof(Queue));
    queue->rear=-1;
    queue->front=-1;
    printf("initialised\n");
}
bool isempty(){
    return queue->front==-1 || queue->front>queue->rear;
}
bool isfull(){
    return queue->front==(queue->rear+1)%size;
}
void enqueue(int data){
    if(isfull()){
        printf("stack overflow\n");
    }
    if(queue->front==-1)
        queue->front=0;
    queue->rear=(queue->rear+1)%size;
    queue->arr[queue->rear]=data;
    printf("enqueued\n");
}
void dequeue(){
    if(isempty()){
        printf("queue underflow\n");        
    }
    else{
        queue->front=(queue->front+1)%size;
    }
    printf("dequeued\n");
}
void display(){
    if(isempty()){
        printf("queue empty\n");
    }
    else{
        int temp=queue->front;
        printf("queue: ");
        for(int i=queue->front;i<queue->rear+1;i++){
            printf("%d ",queue->arr[i]);
        }   
        printf("\n");
    }
}
void main(){
    init();
    enqueue(10);
    enqueue(20);
    dequeue();
    display();
}
