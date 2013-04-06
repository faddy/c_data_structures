#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;


node* newNode(int d){
    node* p = (node*)malloc(sizeof(node));
    p->data = d;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void printTreeInOrder(node* root){
    if(root==NULL) return;
    printTreeInOrder(root->left);
    printf("%d  ",root->data);
    printTreeInOrder(root->right);
}

void insert(node** x, int d){
    node* new = newNode(d);
    if(*x==NULL) *x = new;
    else {
	
    }
}

int lookup(node* root, int d){
    if(root==NULL) 
	return 0;
    if(d == root->data) 
	return 1;
    if( d < root->data ) 
	return( lookup(root->left, d) );
    else 
	return( lookup(root->right, d) );
}

int main(){

    node* root = (node*)malloc(sizeof(node));
    root = NULL;
    insert(&root, 1);
    printTreeInOrder(root);
    return 1;
}
