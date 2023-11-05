#include<stdio.h>
#include<stdlib.h>
struct stack{
        unsigned capacity;
        int top;
        int *array;
};

struct stack * create(unsigned cap){
    struct stack * stack= (struct stack*)malloc (sizeof(struct stack *));
    stack->capacity=cap;
    stack->top=-1;
    stack->array=(int *)malloc(stack->capacity*(sizeof(int )));
    return stack;
}
void push(struct stack * stack , int data)
{
    if( stack->top == stack->capacity-1)
        printf("\nstack is full can't push %d",data);
    else{
        stack->array[++stack->top]=data;
        printf("\n%d pushed to stack", data); 
      
    }
}

int* pop(struct stack * stack){

    if(stack -> top == -1)
        printf("\nstack is empty can't pop");
    else{
        
        printf("\n%d popped from stack", stack->array[stack->top]); 
        stack->array[stack->top--];
        }
}


void display(struct stack * stack){
    if(stack -> top == -1)
        printf("\nstack is empty can't display");
    else{
        int i;
        printf("\nprinting the stack  :  ");
        for(i=0;i<=stack->top;i++)
            printf("%d ",stack->array[i]);
    }
}
int main(){
    struct stack * stack=create(5);
    printf("\nsizeof( stack->array ) : %d",sizeof( stack->array ));
    printf("\nstack->top : %d",stack->top);
    
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);
    
    display(stack);
    push(stack,6);
    display(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    display(stack);
    

    
}