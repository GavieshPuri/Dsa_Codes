#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left , *right;
};


struct node * newNode(int value){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new -> data= value;
    new -> left = new -> right = NULL;
    return new;
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
         
        // Compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        // Use the larger one
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
// Function to print level order traversal a tree
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 


void inorder(struct node* node)
{   
    
    if (node == NULL)
        return;
 
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
}

void preorder(struct node* node)
{   
    
    if (node == NULL)
        return;
    printf("%d ",node->data);
    inorder(node->left);
    inorder(node->right);
}

void postorder(struct node* node)
{   
    
    if (node == NULL)
        return;
 
    inorder(node->left);
    inorder(node->right);
    printf("%d ",node->data);
}

struct node * minimum(struct node * node){
    if (node->left == NULL)
        return node;
    else
        return minimum(node->left);
}

struct node * insert(struct node * node , int value){
    if(node == NULL)
        return newNode(value);
    
    if(node->data < value)
        node->right = insert(node->right,value);
    
    if(node->data > value)
        node->left = insert(node->left,value);
    
    return node;
}

struct node* search(struct node * node , int value){
    if(node == NULL || node->data == value)
        return node;

    if(node->data > value)
        return search(node -> left , value);

    if(node -> data < value)
        return search(node -> right , value);
}
struct node* take_Input(struct node * node){
    printf("   !!!   enter value and to exit press -1    !!!   ");
    int value;
    scanf("%d",&value); 
    while(value != -1){
        node=insert(node,value);
        scanf("%d",&value);
    }
    return node;
}


struct node*  delete(struct node * node , int value){


    if(node == NULL){
        return node;
        }
        
    else if( value > node -> data){
        node -> right= delete(node -> right,value);
        return node;
    }
    else if(value < node -> data){
        node -> left= delete(node -> left,value);
        return node;
    }
       
    else {
         //no child
        if( node -> right == NULL && node -> left == NULL ){
            free(node);
            return NULL;
        
       
        }
        //single child
        if(node -> right == NULL || node -> left == NULL){
                if ( node -> right == NULL ){
                node->data=node->left->data;
                return node->left;
                }
            if ( node -> left == NULL ){
                node->data=node->right->data;
                return node->right;
            }
            return node;
         }
        //two childs
        if( node -> right != NULL && node -> left != NULL ) {
        
            struct node * t = minimum(node->right);
            node->data=t->data;
            node->right = delete(node->right,t->data);
            return node;
        }
    }
}


int main(){
    struct node* root=NULL;
    int value;
    printf("enter data to create BST or -1 to stop the loop \n");
    
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,1);
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,6);
    root=insert(root,9);
    

    printf("\nprinting the tree ");
    printf("\nINORDER:\n");
    inorder(root);
    /*printf("\nPREORDER:\n");
    preorder(root);
    printf("\nPOSTORDER:\n");
    postorder(root);*/
    printf("\nlevel order:\n");
    printLevelOrder(root);
    
    printf("\n\ndeleting 2");
    root=delete(root,2);

    printf("\nprinting the tree ");
    printf("\nINORDER:\n");
    inorder(root);
    printf("\nPREORDER:\n");
    preorder(root);
    printf("\nlevel order:\n");
    printLevelOrder(root);
    
    printf("\n\ndeleting 6");
    root=delete(root,6);

    printf("\nprinting the tree ");
    printf("\nINORDER:\n");
    inorder(root);
    printf("\nPREORDER:\n");
    preorder(root);
    printf("\nlevel order:\n");
    printLevelOrder(root);
    
    
    printf("\n\ndeleting 5");
    root=delete(root,5);

    printf("\nprinting the tree ");
    printf("\nPREORDER:\n");
    preorder(root);
     printf("\nINORDER:\n");
    inorder(root);
    printf("\nPREORDER:\n");
    preorder(root);
    printf("\nlevel order:\n");
    printLevelOrder(root);


    return 0;
}