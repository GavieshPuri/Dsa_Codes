#include<stdio.h>
#include<stdlib.h>

struct Queue{
    unsigned capacity;
    int front;
    int rear;
    int *array;
};

struct Queue * create(unsigned capacity){
    struct Queue* queue =( struct Queue*)malloc(sizeof(struct Queue*));
    queue -> capacity = capacity;
    queue -> front = queue -> rear = -1;
    queue -> array = (int*)malloc(queue -> capacity*sizeof(int));
    return queue;
}

void enque(struct Queue * queue,int data){

    if(queue -> rear == queue -> capacity-1)
        printf("\nfull hai isliye %d ko insert nhi kar sakte\n",data);

    else if(queue->rear == -1)
    {     
        queue -> rear = queue -> front = 0;
        queue -> array [ queue -> rear ] = data;
         printf("\n%d enqued in queue", data); 
    }
    else{
        queue -> array [ ++queue -> rear ] = data; 
         printf("\n%d enqued in queue", data);
    }
}

void deque(struct Queue * queue)
{
    if( queue -> rear == -1 )
        printf("\nempty hai \n");

    else if( queue -> rear == queue -> front ){
         printf("\n%d popped from stack", queue -> array [ queue -> front ] ); 
        queue -> rear = queue -> front = -1;

    }
    else{
        printf("\n%d popped from stack", queue -> array [ queue -> front ] );
        queue -> array [ ++queue -> front ];
    }
}

void display(struct Queue *queue){

    if ( queue -> rear == -1 )
        printf("\nempty hai \n");

    else{
        int i;
        printf("\nQueue :   ");
        for( i = queue -> front ; i <= queue -> rear ; i++ )
            printf("%d ",queue -> array [ i ] );
    }
}
int main(){
    printf("\nprogram started\n");
    struct Queue * queue=create(5);
    printf("\nqueue started\n");
    enque(queue,1);
    enque(queue,2);
    enque(queue,3);
    enque(queue,4);
    enque(queue,5);
    enque(queue,6);

    display(queue);

    deque(queue);
    deque(queue);
    deque(queue);
    deque(queue);
    deque(queue);

    display(queue);

}   