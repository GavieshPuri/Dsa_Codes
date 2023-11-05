#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left , *right ;
};
struct node * newNode(int data){
    struct node * new=(struct node*) malloc(sizeof(struct node));
    new ->data=data;
    new->left=new->right=NULL;
    return new;
}
void preorder(struct node* node)
{   
    
    if (node == NULL)
        return;
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
}
struct node * insert(struct node * node){
    
    int data;
    printf("enter the data:");
    scanf("%d",&data);
    
    node=newNode(data);

    if(data ==-1)
        return NULL;

    printf("enter value in %d left:\n",node->data);
    node -> left = insert ( node -> left ) ;
    printf("enter value in %d right:\n",node->data);
    node -> right = insert ( node -> right ) ;
    return node;

}
int main(){
    struct node * root=NULL;
    root=insert(root);
    printf("\nprinting the tree\n");
    preorder(root);
    
}