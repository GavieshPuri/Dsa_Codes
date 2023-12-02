#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void printArray(int arr[], int size)
{
    int i;
    printf("\nPrinting Array:\t");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
void bubleSort(int arr[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }    
        
    
}
void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){int min=i;
        for(int j=i;j<n;j++){
            if(arr[min]>arr[j])
                min=j;
        }
        if(arr[min]!=arr[i])
            swap(&arr[min],&arr[i]);
            
    }
}
void merge(int arr[],int l ,int m,int r){
    int a=m-l+1;
    int b=r-m;
    int t1[a],t2[b];
    int i,j,k=l;
    for(i=0;i<a;i++)
        t1[i]=arr[k++];
    for(j=0;j<b;j++)
        t2[j]=arr[k++];

    i=0,j=0,k=l;

    while(i<a && j<b){
        if(t1[i]<t2[j])
            arr[k++]=t1[i++];
        if(t1[i]>t2[j])
            arr[k++]=t2[j++];
    }
    while(i<a)
        arr[k++]=t1[i++];
    while(j<b)
        arr[k++]=t2[j++];

}
void mergesort(int arr[],int l ,int r){
    if(l<r){
    int m=(l+r)/2;

    mergesort(arr,l,m);
    mergesort(arr,m+1,r);

    merge(arr,l,m,r);
    }
}
int part(int arr[],int l,int r){
    int pivot=arr[r];
    int i=(l-1);

    for(int j=l;j<=r;j++){
        if(arr[j]<pivot)
            {
                i++;
                swap(&arr[j],&arr[i]);
            }

    }
    swap(&arr[i+1],&arr[r]);
    return (i+1);
}
void quicksort(int arr[],int l ,int r){
    if(l<r)
        {
            int pi=part(arr,l,r);
            quicksort(arr,l,pi-1);
            quicksort(arr,pi+1,r);
        }
}
int main()
{
    printf("Hello World\n");
    
    int arr[]={5,4,3,2,1};
    int n=5;
    printf("\nbefore:\t");
    printArray(arr,n);
    quicksort(arr,0,n-1);
    printf("\nafter:\t");
    printArray(arr,n);
    return 0;
}
