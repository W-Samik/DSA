#include<stdio.h>
#include<stdlib.h>
void printarr(int a[],int n){
    printf("array: ");
    for(int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}
void bubble(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void selection(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
void insertion(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int partition(int a[],int low,int high){
    int pivot=a[low];
    int i=low+1;
    int j=high;
    do{
        while(i<=high && a[i]<=pivot){
            i++;
        }
        while(j>=low && a[j]>pivot){
            j--;
        }
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
} 
void quicksort(int a[],int low,int high){
    int part_index;
    if(low<high){
        part_index=partition(a,low,high);
        quicksort(a,low,part_index-1);
        quicksort(a,part_index+1,high);
    }
}
int main(){
    int a[]={7,1,4,8,4,55};
    int size=6;
    printarr(a,size);
    bubble(a,size);
    printarr(a,size);
}